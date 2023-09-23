#include "clientwaitwindow.h"
#include "ui_clientwaitwindow.h"
#include "person.h"
#include <QTimer>
#include <QSoundEffect>
#include "playwindow.h"


extern Person *User;
PlayWindow*playWindow;
extern QSoundEffect*clickSound;
static bool closeWindowStatus=false;

using namespace std;

ClientWaitWindow::ClientWaitWindow(QMainWindow*personalwindow,QMainWindow*prewindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWaitWindow)
{
    ui->setupUi(this);
    setFixedSize(1280,700);
    personalWindow=personalwindow;
    preWindow=prewindow;

    QIcon windowsIcon(":/new/image/gamename.png");
    this->setWindowIcon(windowsIcon);
    this->setWindowTitle("Waiting for the server to complete");

    //sending player information like name and cup numbers and profile picture to server
    // and server sends this information to other clients
    sendPlayerInformationToServer();


    ui->background->showFullScreen();

    ui->backButton->setStyleSheet("border:none");
    ui->backButton->setIcon(QIcon(":/new/image/icons8-back-48.png"));
    ui->backButton->setIconSize(QSize(40,40));
    connect(ui->backButton,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    ui->backButton->hide();// hiding backButton

    ui->profileLabel1->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileLabel2->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileLabel3->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    ui->profileLabel4->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);

    ui->disconnectButton->setStyleSheet("border:none");
    connect(ui->disconnectButton,SIGNAL(clicked(bool)),this,SLOT(disconnectButtonClicked()));

    if(User->get_gender()=="Male"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(0, 170, 255);");
    }
    else if(User->get_gender()=="Female"){
        ui->guideTextEdit->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(255, 85, 127);");
    }

    ui->profileLabel1->hide();
    ui->nameLabel1->hide();
    ui->cupLabel1->hide();
    ui->cupNumberLabel1->hide();
    ui->label_3->hide();

    ui->profileLabel2->hide();
    ui->nameLabel2->hide();
    ui->cupLabel2->hide();
    ui->cupNumberLabel2->hide();
    ui->label_4->hide();

    ui->profileLabel3->hide();
    ui->nameLabel3->hide();
    ui->cupLabel3->hide();
    ui->cupNumberLabel3->hide();
    ui->label_5->hide();

    ui->profileLabel4->hide();
    ui->nameLabel4->hide();
    ui->cupLabel4->hide();
    ui->cupNumberLabel4->hide();
    ui->label_6->hide();

    t=new std::thread(&ClientWaitWindow::readInformationSentByServer,this);
    ui->guideTextEdit->setReadOnly(true);
    b=false;
    connect(this,SIGNAL(setguideTextEdit(QString,int)),this,SLOT(setSkullKingWords(QString,int)));

    playWindow=new PlayWindow(personalWindow);
}

ClientWaitWindow::~ClientWaitWindow()
{
    delete ui;
    t->join();
}

void ClientWaitWindow::sendPlayerInformationToServer()
{
    //if(User.get_client()->getConnectionStatus()==true)
    {
        QByteArray information;
        QDataStream out(&information,QIODevice::WriteOnly);
        // 'a' tell the server that "add" the clients to the list of connected clients
        out<<'a'<<User->get_name()<<User->get_cup()<<User->get_profile_picture();
        User->get_client()->writeInformation(information);
        if(User->get_client()->getSendStatus()==true){
          //  t=new std::thread(&ClientWaitWindow::readInformationSentByServer,this);
        }
    }
}

void ClientWaitWindow::readInformationSentByServer()
{
    QString serverName,clientName;
    int serverCapacity,numberOfConnectedClients,clientCupNumber;
    QPixmap clientProfilePicture;
    QMessageBox message;

    char mainCode ,subCode;

    //mainCode        | Received Information
    //----------------------------------------------------------------------------------------------------------------
    // 'b' "begin"    | server name - server capacity - number of connected clients - connected clients information
    // ---------------------------------------------------------------------------------------------------------------
    // 'a' "add"      | new client name - new client's cups number - new client's profile picture
    //----------------------------------------------------------------------------------------------------------------
    // 'd' "delete"   | 'c' "a client deleted" - deleted client's name
    //----------------------------------------------------------------------------------------------------------------
    // 'd' "delete"   | 's' "server deleted"
    //----------------------------------------------------------------------------------------------------------------
    // 'p' "play starts"
    //----------------------------------------------------------------------------------------------------------------
    // 'r' "reject"
    while(true){
        if(closeWindowStatus==true)
          break;

        if(User->get_client()->getReceiveStatus()==true){
          QByteArray receivedInformation="";/*=User->get_client()->readInformation()*/

          emit User->get_client()->readSignal(&receivedInformation);
          while(receivedInformation=="");
            QDataStream in(&receivedInformation,QIODevice::ReadOnly);
            in>>mainCode;
            switch(mainCode){
            case 'r':
                message.setText("The server is complete.");
                message.setIcon(QMessageBox::Critical);
                message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                message.setStyleSheet("background-color: rgb(236, 197, 119)");
                message.exec();
                if(message.Ok){
                    QTimer::singleShot(0,this,[this](){
                        closeWindowStatus=true;

                        this->preWindow->showMaximized();
                        this->close();
                    });
                }
                break;

            case 'b':
                in>>serverName>>serverCapacity>>numberOfConnectedClients;
                emit setguideTextEdit(serverName,serverCapacity);
                for(int i=0;i<numberOfConnectedClients;i++){
                    in>>clientName>>clientCupNumber>>clientProfilePicture;
                    addNewClientToList(clientName,clientCupNumber,clientProfilePicture);
                }
               // addNewClientToList(User->get_name(),User->get_cup(),User->get_profile_picture());
                break;

            case 'a':
                in>>clientName>>clientCupNumber>>clientProfilePicture;
                addNewClientToList(clientName,clientCupNumber,clientProfilePicture);
                break;

            case 'd':
                in>>subCode;
                switch(subCode){

                case 'c':
                    in>>clientName;
                    for(vector<ClientInformation>::iterator it=connectedClientsToServerList.begin();
                         it!=connectedClientsToServerList.end();it++){
                        if((*it).name==clientName){
                            connectedClientsToServerList.erase(it);
                            showClientListInGUI();
                            break;
                        }
                    }
                    break;

                case 's':
                    User->get_client()->closeSocket();
                    message.setText("The server has given up on continuing the war, so the war doesn't start.");
                    message.setIcon(QMessageBox::Critical);
                    message.setWindowIcon(QIcon(":/new/image/gamename.png"));
                    message.setStyleSheet("background-color: rgb(236, 197, 119)");
                    message.exec();
                    if(message.Ok){
                        QTimer::singleShot(0,this,[this](){
                            closeWindowStatus=true;

                            this->preWindow->showMaximized();
                            this->close();
                        });
//                        preWindow->showMaximized();
//                        this->close();
                    }
                    break;
                }
                break;

            case 'p':
                // I must show play window and close other windows.
                //note that when server sent 'p' client may be in other windows
                //and those window must be closed
                //playWindow=new PlayWindow(personalWindow);
                QTimer::singleShot(0,this,[this](){

                    closeWindowStatus=true;

                   playWindow->showMaximized();
                    this->close();
                });
                break;
            }
        }
        }
    }


void ClientWaitWindow::backButtonClicked()
{
    clickSound->play();

    closeWindowStatus=true;

    if(User->get_client()->getConnectionStatus()==true)
        personalWindow->showMaximized();
    else
        preWindow->showMaximized();

    this->close();

}

void ClientWaitWindow::disconnectButtonClicked()
{
    clickSound->play();

    QByteArray information;
    QDataStream out(&information,QIODevice::WriteOnly);
    out<<'d'<<User->get_name(); // d "delete" tells the server that client want to disconnect and server deleted it from its list
    User->get_client()->writeInformation(information);
    while(User->get_client()->getSendStatus()==false);
    User->get_client()->closeSocket();

    closeWindowStatus=true;

    preWindow->showMaximized();
    this->close();
}

void ClientWaitWindow::addNewClientToList(QString clientName, int clientCupNumber,QPixmap clientProfilePicture)
{
    ClientInformation newClient;
    newClient.name=clientName;
    newClient.cupNumber=clientCupNumber;
    newClient.profilePicture=clientProfilePicture;

    connectedClientsToServerList.push_back(newClient);

    showClientListInGUI();
}

void ClientWaitWindow::showClientListInGUI()
{
    if(connectedClientsToServerList.size()==0){
        ui->profileLabel1->hide();
        ui->nameLabel1->hide();
        ui->cupLabel1->hide();
        ui->cupNumberLabel1->hide();
        ui->label_3->hide();

        ui->profileLabel2->hide();
        ui->nameLabel2->hide();
        ui->cupLabel2->hide();
        ui->cupNumberLabel2->hide();
        ui->label_4->hide();

        ui->profileLabel3->hide();
        ui->nameLabel3->hide();
        ui->cupLabel3->hide();
        ui->cupNumberLabel3->hide();
        ui->label_5->hide();

        ui->profileLabel4->hide();
        ui->nameLabel4->hide();
        ui->cupLabel4->hide();
        ui->cupNumberLabel4->hide();
        ui->label_6->hide();

    }
    else if(connectedClientsToServerList.size()==1){

        {
            QPixmap scaledImage(connectedClientsToServerList[0].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel1->setPixmap(scaledImage);
        ui->nameLabel1->setText(connectedClientsToServerList[0].name);
        ui->cupNumberLabel1->setText(QString::number(connectedClientsToServerList[0].cupNumber));
        }

        ui->profileLabel1->show();
        ui->nameLabel1->show();
        ui->cupLabel1->show();
        ui->cupNumberLabel1->show();
        ui->label_3->show();

        ui->profileLabel2->hide();
        ui->nameLabel2->hide();
        ui->cupLabel2->hide();
        ui->cupNumberLabel2->hide();
        ui->label_4->hide();

        ui->profileLabel3->hide();
        ui->nameLabel3->hide();
        ui->cupLabel3->hide();
        ui->cupNumberLabel3->hide();
        ui->label_5->hide();

        ui->profileLabel4->hide();
        ui->nameLabel4->hide();
        ui->cupLabel4->hide();
        ui->cupNumberLabel4->hide();
        ui->label_6->hide();

    }
    else if(connectedClientsToServerList.size()==2){
        {
        QPixmap scaledImage(connectedClientsToServerList[0].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel1->setPixmap(scaledImage);
        ui->nameLabel1->setText(connectedClientsToServerList[0].name);
        ui->cupNumberLabel1->setText(QString::number(connectedClientsToServerList[0].cupNumber));
        }

        {
        QPixmap scaledImage(connectedClientsToServerList[1].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel2->setPixmap(scaledImage);
        ui->nameLabel2->setText(connectedClientsToServerList[1].name);
        ui->cupNumberLabel2->setText(QString::number(connectedClientsToServerList[1].cupNumber));
        }

        ui->profileLabel1->show();
        ui->nameLabel1->show();
        ui->cupLabel1->show();
        ui->cupNumberLabel1->show();
        ui->label_3->show();

        ui->profileLabel2->show();
        ui->nameLabel2->show();
        ui->cupLabel2->show();
        ui->cupNumberLabel2->show();
        ui->label_4->show();

        ui->profileLabel3->hide();
        ui->nameLabel3->hide();
        ui->cupLabel3->hide();
        ui->cupNumberLabel3->hide();
        ui->label_5->hide();

        ui->profileLabel4->hide();
        ui->nameLabel4->hide();
        ui->cupLabel4->hide();
        ui->cupNumberLabel4->hide();
        ui->label_6->hide();

    }
    else if(connectedClientsToServerList.size()==3){
        {
        QPixmap scaledImage(connectedClientsToServerList[0].profilePicture);
       scaledImage= scaledImage.scaled(51,51);
        ui->profileLabel1->setPixmap(scaledImage);
        ui->nameLabel1->setText(connectedClientsToServerList[0].name);
        ui->cupNumberLabel1->setText(QString::number(connectedClientsToServerList[0].cupNumber));
        }
        {
        QPixmap scaledImage(connectedClientsToServerList[1].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel2->setPixmap(scaledImage);
        ui->nameLabel2->setText(connectedClientsToServerList[1].name);
        ui->cupNumberLabel2->setText(QString::number(connectedClientsToServerList[1].cupNumber));
        }
        {
        QPixmap scaledImage(connectedClientsToServerList[2].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel3->setPixmap(scaledImage);
        ui->nameLabel3->setText(connectedClientsToServerList[2].name);
        ui->cupNumberLabel3->setText(QString::number(connectedClientsToServerList[2].cupNumber));
        }


        ui->profileLabel1->show();
        ui->nameLabel1->show();
        ui->cupLabel1->show();
        ui->cupNumberLabel1->show();
        ui->label_3->show();

        ui->profileLabel2->show();
        ui->nameLabel2->show();
        ui->cupLabel2->show();
        ui->cupNumberLabel2->show();
        ui->label_4->show();

        ui->profileLabel3->show();
        ui->nameLabel3->show();
        ui->cupLabel3->show();
        ui->cupNumberLabel3->show();
        ui->label_5->show();

        ui->profileLabel4->hide();
        ui->nameLabel4->hide();
        ui->cupLabel4->hide();
        ui->cupNumberLabel4->hide();
        ui->label_6->hide();
    }
    else if(connectedClientsToServerList.size()==4){
        {
        QPixmap scaledImage(connectedClientsToServerList[0].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel1->setPixmap(scaledImage);
        ui->nameLabel1->setText(connectedClientsToServerList[0].name);
        ui->cupNumberLabel1->setText(QString::number(connectedClientsToServerList[0].cupNumber));
    }
    {
        QPixmap scaledImage(connectedClientsToServerList[1].profilePicture);
        scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel2->setPixmap(scaledImage);
        ui->nameLabel2->setText(connectedClientsToServerList[1].name);
        ui->cupNumberLabel2->setText(QString::number(connectedClientsToServerList[1].cupNumber));
    }
    {
        QPixmap scaledImage(connectedClientsToServerList[2].profilePicture);
       scaledImage= scaledImage.scaled(51,51);
        ui->profileLabel3->setPixmap(scaledImage);
        ui->nameLabel3->setText(connectedClientsToServerList[2].name);
        ui->cupNumberLabel3->setText(QString::number(connectedClientsToServerList[2].cupNumber));
    }
    {
    QPixmap scaledImage(connectedClientsToServerList[3].profilePicture);
    scaledImage=scaledImage.scaled(51,51);
        ui->profileLabel3->setPixmap(scaledImage);
        ui->nameLabel3->setText(connectedClientsToServerList[3].name);
        ui->cupNumberLabel3->setText(QString::number(connectedClientsToServerList[3].cupNumber));
    }


        ui->profileLabel1->show();
        ui->nameLabel1->show();
        ui->cupLabel1->show();
        ui->cupNumberLabel1->show();
        ui->label_3->show();

        ui->profileLabel2->show();
        ui->nameLabel2->show();
        ui->cupLabel2->show();
        ui->cupNumberLabel2->show();
        ui->label_4->show();

        ui->profileLabel3->show();
        ui->nameLabel3->show();
        ui->cupLabel3->show();
        ui->cupNumberLabel3->show();
        ui->label_5->show();

        ui->profileLabel4->show();
        ui->nameLabel4->show();
        ui->cupLabel4->show();
        ui->cupNumberLabel4->show();
        ui->label_6->show();
    }
}

void ClientWaitWindow::closeEvent(QCloseEvent *event)
{
    t->join();
    QMainWindow::closeEvent(event);
}

void ClientWaitWindow::setSkullKingWords(QString serverName,int serverCapacity)
{
    QString s="Commander, now we have to wait until the number of clients connected to "
                                    +serverName+" server reaches "+QString::number(serverCapacity)
                                    +". After that, the war begins.\n\nSkull King";
    ui->guideTextEdit->setText(s);
}

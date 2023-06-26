QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buy.cpp \
    game.cpp \
    login.cpp \
    main.cpp \
    person.cpp \
    personalwindow.cpp \
    player.cpp \
    register_login.cpp \
    registeraccount.cpp

HEADERS += \
    buy.h \
    game.h \
    login.h \
    person.h \
    personalwindow.h \
    player.h \
    register_login.h \
    registeraccount.h

FORMS += \
    buy.ui \
    login.ui \
    personalwindow.ui \
    register_login.ui \
    registeraccount.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
   Images.qrc

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlefield.cpp \
    configdlg.cpp \
    constant.cpp \
    gamesourses/background.cpp \
    gamesourses/barragemanager.cpp \
    gamesourses/bullet.cpp \
    gamesourses/bulletmanager.cpp \
    gamesourses/dialogplayer.cpp \
    gamesourses/enemy.cpp \
    gamesourses/enemymanager.cpp \
    gamesourses/gameobj.cpp \
    gamesourses/hero.cpp \
    gamesourses/level0.cpp \
    gamesourses/level0boss.cpp \
    gamesourses/level1.cpp \
    gamesourses/level1boss.cpp \
    gamesourses/level2.cpp \
    gamesourses/level2boss.cpp \
    gamesourses/level3.cpp \
    gamesourses/managerdep.cpp \
    gamesourses/others.cpp \
    gamesourses/prop.cpp \
    gamesourses/propmanager.cpp \
    gamesourses/soundmanager.cpp \
    loadingthread.cpp \
    main.cpp \
    mainwidget.cpp \
    movevector.cpp \
    optionlabel.cpp

HEADERS += \
    battlefield.h \
    configdlg.h \
    constant.h \
    gameheaders/background.h \
    gameheaders/barragemanager.h \
    gameheaders/bullet.h \
    gameheaders/bulletmanager.h \
    gameheaders/dialogplayer.h \
    gameheaders/enemy.h \
    gameheaders/enemymanager.h \
    gameheaders/gameobj.h \
    gameheaders/hero.h \
    gameheaders/managerdep.h \
    gameheaders/others.h \
    gameheaders/prop.h \
    gameheaders/propmanager.h \
    gameheaders/soundmanager.h \
    loadingthread.h \
    mainwidget.h \
    movevector.h \
    optionlabel.h

FORMS += \
    configdlg.ui \
    mainwidget.ui

TRANSLATIONS += \
    demo_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=

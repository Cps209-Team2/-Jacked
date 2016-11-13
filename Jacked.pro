#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T21:01:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jacked
TEMPLATE = app
INCLUDEPATH += .
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += main.cpp\
    highscore.cpp \
    weapon.cpp \
    melee.cpp \
    ranged.cpp \
    projectile.cpp \
    startwindow.cpp \
    movablelabel.cpp \
    gamewidget.cpp \
    entity.cpp \
    enemy.cpp \
    player.cpp \
    cheater.cpp \
    help.cpp \
    collision.cpp \
    save.cpp \
    playerlabel.cpp \
    enemylabel.cpp \
    world.cpp \
    collisioninfo.cpp \
    highscoreswindow.cpp \
    difficulty.cpp \
    accesslabel.cpp \
    escmenu.cpp

HEADERS  += \
    highscore.h \
    weapon.h \
    melee.h \
    ranged.h \
    projectile.h \
    obstacle.h \
    startwindow.h \
    movablelabel.h \
    gamewidget.h \
    entity.h \
    enemy.h \
    player.h \
    cheater.h \
    help.h \
    collision.h \
    save.h \
    playerlabel.h \
    enemylabel.h \
    world.h \
    collisioninfo.h \
    highscoreswindow.h \
    difficulty.h \
    accesslabel.h \
    escmenu.h

FORMS    += \
    startwindow.ui \
    gamewidget.ui \
    help.ui \
    escmenu.ui \
    highscoreswindow.ui \
    difficulty.ui

QMAKE_CXXFLAGS += -std=c++14

RESOURCES = \
    resources.qrc

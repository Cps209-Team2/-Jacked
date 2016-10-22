#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T21:01:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jacked
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    map.cpp \
    highscore.cpp \
    weapon.cpp \
    melee.cpp \
    ranged.cpp \
    projectile.cpp \
    hitbox.cpp

HEADERS  += gamewindow.h \
    saveload.h \
    character.h \
    Player.h \
    Enemy.h \
    map.h \
    highscore.h \
    weapon.h \
    melee.h \
    ranged.h \
    projectile.h \
    hitbox.h \
    obstacle.h

FORMS    += gamewindow.ui

QMAKE_CXXFLAGS += -std=c++14

RESOURCES += \
    resources.qrc \
    resources.qrc
#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T23:13:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    scene/scene.cpp \
    scene/initscene.cpp \
    qneed.cpp \
    scene/logoscene.cpp \
    scene/choicescene.cpp

HEADERS  += mainwindow.h \
    character.h \
    Types.h \
    scene/scene.h \
    scene/initscene.h \
    qneed.h \
    scene/logoscene.h \
    scene/choicescene.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

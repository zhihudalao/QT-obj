#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T09:10:54
#
#-------------------------------------------------

QT       += core gui
QT      += network
QT      += multimedia
QT      += multimediawidgets
CONFIG += mobility
MOBILITY += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    chatroom.cpp \
    clientsocket.cpp \
    roommanager.cpp \
    videosurface.cpp

HEADERS  += mainwindow.h \
    user.h \
    dialog.h \
    chatroom.h \
    clientsocket.h \
    roommanager.h \
    videosurface.h

FORMS    += mainwindow.ui \
    dialog.ui \
    chatroom.ui


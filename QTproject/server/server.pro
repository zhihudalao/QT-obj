#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T09:11:14
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
QT       += multimedia
QT       += multimediawidgets
CONFIG   += mobility
MOBILITY += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
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
    chat.cpp \
    chatmanager.cpp \
    clientsocket.cpp \
    dbhelper.cpp \
    onlinedao.cpp \
    onlinedaoimp.cpp \
    socketmanager.cpp \
    userdao.cpp \
    userdaoimp.cpp

HEADERS  += mainwindow.h \
    user.h \
    chat.h \
    chatmanager.h \
    clientsocket.h \
    dbhelper.h \
    onlinedao.h \
    onlinedaoimp.h \
    socketmanager.h \
    userdao.h \
    userdaoimp.h

FORMS    += mainwindow.ui

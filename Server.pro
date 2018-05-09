#-------------------------------------------------
#
# Project created by QtCreator 2018-05-07T15:44:28
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    consolePThread.cpp \
    mainThread.cpp

HEADERS += \
    consolePThread.h \
    mainThread.h

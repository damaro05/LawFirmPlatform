#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T13:05:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LawFirmPlatform
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/maintoolbar.cpp \
           src/formtest.cpp \
           src/profileview.cpp

HEADERS += src/mainwindow.h \
           src/maintoolbar.h \
           src/formtest.h \
           src/profileview.h

FORMS += src/forms/mainwindow.ui \
         src/forms/maintoolbar.ui \
         src/forms/formtest.ui \
         src/forms/profileview.ui

RESOURCES += \
    media.qrc


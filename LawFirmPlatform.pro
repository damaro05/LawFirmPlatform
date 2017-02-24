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
           src/profileview.cpp \
           src/lawyerview.cpp \
           src/clientview.cpp \
           src/listviewtemplate.cpp \
           src/notificationview.cpp \
           src/caseview.cpp

HEADERS += src/mainwindow.h \
           src/maintoolbar.h \
     src/formtest.h \
           src/profileview.h \
           src/lawyerview.h \
           src/clientview.h \
           src/listviewtemplate.h \
           src/notificationview.h \
           src/caseview.h

FORMS += src/forms/mainwindow.ui \
         src/forms/maintoolbar.ui \
     src/forms/formtest.ui \
         src/forms/profileview.ui \
         src/forms/listviewtemplate.ui \
         src/forms/notificationview.ui \
         src/forms/caseview.ui


RESOURCES += \
    media.qrc \


#QSystemTrayIcon
#RC_ICONS = LawFirmPlatform.ico
#QMAKE_CXXFLAGS += -std=gnu++14


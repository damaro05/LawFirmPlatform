#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T13:05:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += sql widgets

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
           src/caseview.cpp \
           src/casedetailview.cpp \
           src/caselawyerview.cpp \
           src/casehoursview.cpp \
    src/models/cmodeltableview.cpp \
           src/casedocview.cpp \
           src/tableviewtemplate.cpp \
    src/casecostview.cpp \
    src/faseviewtemplate.cpp \
    src/casefaseview.cpp

HEADERS += src/mainwindow.h \
           src/maintoolbar.h \
     src/formtest.h \
           src/profileview.h \
           src/lawyerview.h \
           src/clientview.h \
           src/listviewtemplate.h \
           src/notificationview.h \
           src/caseview.h \
           src/casedetailview.h \
           src/caselawyerview.h \
           src/casehoursview.h \
    src/sql/connectioncache.h \
    src/models/cmodeltableview.h \
           src/casedocview.h \
           src/tableviewtemplate.h \
    src/casecostview.h \
    src/faseviewtemplate.h \
    src/casefaseview.h

FORMS += src/forms/mainwindow.ui \
         src/forms/maintoolbar.ui \
     src/forms/formtest.ui \
         src/forms/profileview.ui \
         src/forms/listviewtemplate.ui \
         src/forms/notificationview.ui \
         src/forms/caseview.ui \
         src/forms/casedetailview.ui \
         src/forms/tableviewtemplate.ui \
    src/faseviewtemplate.ui \
    src/casefaseview.ui


RESOURCES += \
    media.qrc


#QSystemTrayIcon
#RC_ICONS = LawFirmPlatform.ico
#QMAKE_CXXFLAGS += -std=gnu++14

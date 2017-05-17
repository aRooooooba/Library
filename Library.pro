#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T22:36:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    addpeople.cpp \
    addbook.cpp \
    saveBook.cpp \
    savePeople.cpp \
    loadBook.cpp \
    loadPeople.cpp \
    functions.cpp \
    Queue.cpp \
    Time.cpp \
    copyInfo.cpp \
    Enter.cpp

HEADERS  += mainwindow.h \
    login.h \
    addpeople.h \
    addbook.h \
    dataStruct.h \
    functions.h

FORMS    += mainwindow.ui \
    login.ui \
    addpeople.ui \
    addbook.ui

RESOURCES += \
    pics.qrc

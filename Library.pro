#-------------------------------------------------
#
# Project created by QtCreator 2017-04-09T20:26:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loadBook.cpp \
    loadPeople.cpp \
    loadlogin.cpp \
    saveBook.cpp \
    savePeople.cpp \
    getFirstLetter.cpp \
    editPassword.cpp \
    bookinformation.cpp \
    peopleinformation.cpp \
    bookdetail.cpp \
    peopledetail.cpp \
    copyInfoP.cpp \
    copyInfoB.cpp

HEADERS  += mainwindow.h \
    loadBook.h \
    loadPeople.h \
    loadlogin.h \
    saveBook.h \
    savePeople.h \
    getFirstLetter.h \
    dataStruct.h \
    editPassword.h \
    bookinformation.h \
    peopleinformation.h \
    bookdetail.h \
    peopledetail.h \
    copyinfop.h \
    copyinfob.h

FORMS    += mainwindow.ui \
    loadlogin.ui \
    editpassword.ui \
    bookinformation.ui \
    peopleinformation.ui \
    bookdetail.ui \
    peopledetail.ui

RESOURCES +=

#-------------------------------------------------
#
# Project created by QtCreator 2020-09-11T18:56:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MatrixCaculator
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

CONFIG += C++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myalgorithm.cpp \
    variablemanager.cpp \
    basestructre.cpp \
    addvariable.cpp \
    editvariable.cpp \
    computation.cpp \
    Qnum.cpp \
    Double.cpp

HEADERS += \
        mainwindow.h \
    myalgorithm.h \
    variablemanager.h \
    basestructure.h \
    addvariable.h \
    editvariable.h \
    computation.h \
    field.h \
    matrix.h

FORMS += \
        mainwindow.ui \
    addvariable.ui \
    editvariable.ui

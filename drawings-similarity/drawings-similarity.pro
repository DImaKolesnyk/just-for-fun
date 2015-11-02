#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T18:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawings-similarity
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    DrawingPlace.cpp \
    Controller.cpp

HEADERS  += \
    DrawingPlace.h \
    MainWindow.h \
    contour.h \
    Controller.h \
    tree.h \
    node.h

FORMS    += MainWindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2012-08-15T20:09:51
#
#-------------------------------------------------

QT       += core gui

TARGET = ocrcopy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screenshotfactory.cpp \
    screenshot.cpp

HEADERS  += mainwindow.h \
    screenshotfactory.h \
    screenshot.h

FORMS    += mainwindow.ui

LIBS += -ltesseract \
    -llept





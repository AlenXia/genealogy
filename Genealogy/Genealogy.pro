#-------------------------------------------------
#
# Project created by QtCreator 2021-12-05T10:48:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Genealogy
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


SOURCES += \
        main.cpp \
        mymainwindow.cpp \
    subwidget.cpp \
    overview.cpp \
    delete.cpp \
    find.cpp \
    family.cpp \
    information.cpp \
    add.cpp \
    add2.cpp

HEADERS += \
        mymainwindow.h \
    subwidget.h \
    overview.h \
    delete.h \
    find.h \
    family.h \
    information.h \
    add.h \
    add2.h

FORMS += \
        mymainwindow.ui \
    subwidget.ui \
    overview.ui \
    delete.ui \
    find.ui \
    information.ui \
    add.ui \
    add2.ui

RESOURCES += \
    picture.qrc


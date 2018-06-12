#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T14:45:49
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MUK
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    balafisica.cpp \
    balas.cpp \
    muk.cpp \
    form.cpp \
    principal.cpp \
    controles.cpp \
    login.cpp \
    registro.cpp \
    nivel.cpp \
    imageinicio.cpp

HEADERS += \
        mainwindow.h \
    balafisica.h \
    balas.h \
    muk.h \
    form.h \
    principal.h \
    controles.h \
    login.h \
    registro.h \
    nivel.h \
    imageinicio.h

FORMS += \
        mainwindow.ui \
    form.ui \
    principal.ui \
    controles.ui \
    login.ui \
    registro.ui \
    nivel.ui \
    imageinicio.ui

RESOURCES += \
    resources.qrc

DISTFILES +=

#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT+=sql
CONFIG+=console
QT       += core gui sql printsupport network multimedia multimediawidgets charts widgets axcontainer
QT += serialport
QT +=charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
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

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    employes.cpp \
    excel.cpp \
    exportexcelobject.cpp \
    fournisseur.cpp \
    histo.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    notif.cpp \
    produit.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtp.cpp \
    vol.cpp \
    voyageur.cpp

HEADERS += \
    arduino.h \
    employes.h \
    excel.h \
    exportexcelobject.h \
    fournisseur.h \
    histo.h \
        mainwindow.h \
    connection.h \
    notif.h \
    produit.h \
    qcustomplot.h \
    qrcode.h \
    smtp.h \
    vol.h \
    voyageur.h

FORMS += \
        mainwindow.ui \
        stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



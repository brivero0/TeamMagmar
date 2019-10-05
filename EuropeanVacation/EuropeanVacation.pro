#-------------------------------------------------
#
# Project created by QtCreator 2019-03-27T14:11:09
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BulkClub
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
    afooddialog.cpp \
        main.cpp \
    admin.cpp \
    login.cpp \
    databasemanger.cpp \
    traveler.cpp \
    tDestinations.cpp \
    tFoods.cpp \
    aDestinations.cpp \
    aFoods.cpp \
    tconfirmparis.cpp \
    tconfirmcustom.cpp \
    ttravelsimulation.cpp \
    tconfirmlondon.cpp \
    updatefood.cpp


HEADERS += \
    admin.h \
    afooddialog.h \
    login.h \
    databasemanger.h \
    traveler.h \
    tDestinations.h \
    tFoods.h \
    aDestinations.h \
    aFoods.h \
    tconfirmparis.h \
    tconfirmcustom.h \
    ttravelsimulation.h \
    tconfirmlondon.h \
    updatefood.h


FORMS += \
    admin.ui \
    afooddialog.ui \
    login.ui \
    traveler.ui \
    tDestinations.ui \
    tFoods.ui \
    aDestinations.ui \
    aFoods.ui \
    tconfirmparis.ui \
    tconfirmcustom.ui \
    ttravelsimulation.ui \
    tconfirmlondon.ui \
    updatefood.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

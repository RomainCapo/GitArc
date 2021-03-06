#-------------------------------------------------
#
# Project created by QtCreator 2018-11-12T13:14:58
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitArc
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
    gaviewgame.cpp \
    gaverticalnotes.cpp \
    gahorizontalnotesbar.cpp \
    gagame.cpp \
    ganotereader.cpp \
    ganote.cpp \
    gagamerightpannel.cpp \
    gamainmenu.cpp \
    gashowabout.cpp \
    gascore.cpp \
    gashowoptions.cpp \
    gasettings.cpp \
    gashowrules.cpp

HEADERS += \
    gaviewgame.h \
    gaverticalnotes.h \
    gahorizontalnotesbar.h \
    gagame.h \
    ganotereader.h \
    ganote.h \
    gagamerightpannel.h \
    gamainmenu.h \
    gashowabout.h \
    gascore.h \
    gashowoptions.h \
    gasettings.h \
    gashowrules.h \
    gaconstants.h

RESOURCES += \
    rsc.qrc

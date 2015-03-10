TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    MyCaT.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    myCat.h


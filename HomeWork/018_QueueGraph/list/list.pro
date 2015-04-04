TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    list.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h


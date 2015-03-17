TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    date.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    date.h


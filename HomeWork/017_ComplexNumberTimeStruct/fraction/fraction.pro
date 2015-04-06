TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    fraction.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fraction.h


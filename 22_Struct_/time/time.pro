TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    time.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    time.h


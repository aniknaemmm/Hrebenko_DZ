TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    phil.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    phil.h


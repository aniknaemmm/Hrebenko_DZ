TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS = -std=c11
SOURCES += main.c \
    phil.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    phil.h


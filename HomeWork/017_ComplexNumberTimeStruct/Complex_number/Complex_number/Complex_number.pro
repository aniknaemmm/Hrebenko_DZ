TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS +=-std=c11

SOURCES += main.c \
    complex.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    complex.h


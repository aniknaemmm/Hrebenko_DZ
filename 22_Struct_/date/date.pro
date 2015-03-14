TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11
SOURCES += main.c \
    date.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    date.h


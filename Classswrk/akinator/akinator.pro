TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    akinator.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    akinator.h


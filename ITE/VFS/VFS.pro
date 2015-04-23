TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    VFS.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    VFS.h


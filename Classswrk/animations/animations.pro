TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11

SOURCES += main.c

include(deployment.pri)
qtcAddDeployment()


unix|win32: LIBS += -lSDL2

unix|win32: LIBS += -lSDL2_image

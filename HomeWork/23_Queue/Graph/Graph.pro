TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11
SOURCES += main.c \
        Graph.c\

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
      Graph.h\


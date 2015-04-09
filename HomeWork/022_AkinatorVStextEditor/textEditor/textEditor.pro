TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS = -std=c11
SOURCES += main.c \
    textEditor.c \
    ../../../modules/src/ncursesinit.c

include(deployment.pri)
qtcAddDeployment()


unix|win32: LIBS += -lncurses

HEADERS += \
    textEditor.h \
    ../../../modules/include/ncursesinit.h

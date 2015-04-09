TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS = -std=c++11
SOURCES += main.cpp \
    sdlwrapper.cpp

include(deployment.pri)
qtcAddDeployment()


unix|win32: LIBS += -lSDL2

HEADERS += \
    sdlwrapper.h

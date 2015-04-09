TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS = -std=c++11
SOURCES += main.cpp \
    sdlwrapper.cpp \
    lisag.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sdlwrapper.h \
    lisag.h


unix|win32: LIBS += -lSDL2

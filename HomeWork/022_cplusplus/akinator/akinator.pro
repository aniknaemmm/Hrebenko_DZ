TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS = -std=c++11
SOURCES += main.cpp \
    akinator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    akinator.h


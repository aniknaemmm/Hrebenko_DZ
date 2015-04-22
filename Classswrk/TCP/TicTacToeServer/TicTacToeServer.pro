TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS = -std=c11
SOURCES += main.c \
    ../../../HomeWork/015_TicTacToeArraySort/TicTacToe20x20/TTT.c \
    ../../../modules/src/ncursesinit.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../../HomeWork/015_TicTacToeArraySort/TicTacToe20x20/TTT.h \
    ../../../modules/include/ncursesinit.h


unix|win32: LIBS += -lncurses

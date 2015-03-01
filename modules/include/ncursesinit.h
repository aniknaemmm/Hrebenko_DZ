#ifndef NCURSES_INCLUDED
#define NCURSES_INCLUDED

#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE	199309L
#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>


void treatSigWinch(int signo);
void initialiseProgram();
enum Colors {normal,green,red,blue};


#endif // TTT_H_INCLUDED

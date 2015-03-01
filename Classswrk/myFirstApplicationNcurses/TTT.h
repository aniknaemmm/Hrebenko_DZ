#ifndef TTT_H_INCLUDED
#define TTT_H_INCLUDED

#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE	199309L
#define SIZE 20
#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>


void treatSigWinch(int signo);
void initialiseProgram();
enum Colors{normal,green,red,blue};
void drawTable(int mass[][SIZE]);
void drwka(int mass[][SIZE]);
void playGame(int mass[][SIZE]);
int chekWinGame(int mass[][SIZE]);


#endif // TTT_H_INCLUDED

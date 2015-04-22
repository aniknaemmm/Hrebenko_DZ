#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../../../modules/include/ncursesinit.h"
#include "../../../HomeWork/015_TicTacToeArraySort/TicTacToe20x20/TTT.h"
#define SIZE 20
void toTransfer(int mass[][SIZE], int buf[]);
void backTransfer(int mass[][SIZE], int buf[]);
int main(int argc, char **argv)
{
    initialiseProgram();
    int aSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(aSocket < 0)
    {
        write(2, "ERR:socket\n", 11);
        return 1;
    }

    int error;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7500);
    peer.sin_addr.s_addr = inet_addr(argv[1]);

    error = connect(aSocket, (struct sockaddr *)&peer, sizeof(peer));

    if(error)
    {
        write(2, "ERR:connect\n", 12);
        return 1;
    }

    int exit = 0;
    int buf[SIZE * SIZE] = {0};
    int mass[SIZE][SIZE] = {{0}};
    drawTable();

    while(!exit)
    {

        playGame(mass);
        toTransfer(mass, buf);
        error = write(aSocket, buf, SIZE  * SIZE * sizeof(int));


        if(error <= 0)
        {
            write(2, "ERR:write\n", 10);
            return 1;
        }

        if(chekWinGame(mass) != 0)
        {
            move(21, 0);
            printw("you win");
            exit = 1;
        }
        else
        {
            error = read(aSocket, buf, SIZE  * SIZE * sizeof(int));
            backTransfer(mass, buf);

            if(error <= 0)
            {
                write(2, "ERR:read\n", 9);
                return 1;
            }

            drwka(mass);

            if(chekWinGame(mass) != 0)
            {
                move(21,0);
                printw("you lose");
                exit = 1;
            }
        }

    }
refresh();
    getchar();
    endwin();
    return 0;
}

void toTransfer(int mass[][SIZE], int buf[])
{
    int num = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int k = 0; k < SIZE; k++)
        {
            buf[num] = mass[i][k];
            num++;
        }
    }
}
void backTransfer(int mass[][SIZE], int buf[])
{
    int num = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int k = 0; k < SIZE; k++)
        {
            mass[i][k] = buf[num] ;
            num++;
        }
    }
}

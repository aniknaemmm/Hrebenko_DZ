#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include "../../../modules/include/ncursesinit.h"
#include "../../../HomeWork/015_TicTacToeArraySort/TicTacToe20x20/TTT.h"
void toTransfer(int mass[][SIZE], int buf[]);
void backTransfer(int mass[][SIZE], int buf[]);
int main(void)
{
    initialiseProgram();
    int exit = 0;
    int mass[SIZE][SIZE] = {{0}};
    int buf[SIZE * SIZE] = {0};
    drawTable();
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(listenSocket < 0)
    {
        write(2, "ERR:socket\n", 11);
        return 1;
    }

    int error;
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(7500);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    error = bind(listenSocket, (struct sockaddr *)&local, sizeof(local));

    if(error)
    {
        write(2, "ERR:bind\n", 9);
        return 1;
    }

    error = listen(listenSocket, 5);

    if(error)
    {
        write(2, "ERR:listen\n", 11);
        return 1;
    }

    int aSocket = accept(listenSocket, NULL, NULL);

    if(aSocket < 0)
    {
        write(2, "ERR:accept\n", 11);
        return 1;
    }

    while(!exit)
    {

        error = read(aSocket, buf, SIZE * SIZE * sizeof(int));
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
            refresh();
        }
        else
        {


            playGame(mass);
            toTransfer(mass,buf);
            error = write(aSocket, buf, SIZE * SIZE * sizeof(int));

            if(error <= 0)
            {
                write(2, "ERR:read\n", 9);
                return 1;
            }

            if(chekWinGame(mass) != 0)
            {
                move(21,0);
                printw("you win");
                exit = 1;
                refresh();
            }

        }
    }

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

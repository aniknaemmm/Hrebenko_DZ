#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../../../modules/include/ncursesinit.h"
#define SIZE 20



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


    int clientbuf[SIZE + 1][SIZE] = {{0}};

    while(1)
    {

        playGame(clientbuf);

        if(chekWinGame(clientbuf) != 0)
        {
            //выход
        }
        else
        {

            error = write(aSocket, clientbuf, 128);

            if(error <= 0)
            {
                write(2, "ERR:write\n", 10);
                return 1;
            }
        }


        error = read(aSocket, clientbuf, 128);

        if(error <= 0)
        {
            write(2, "ERR:read\n", 9);
            return 1;
        }

        drwka(clientbuf);
        //write(1, "server: ", 8);
        //write(1, buf, strlen(buf));
        // write(1, "\n", 1);


    }

    endwin();
    return 0;
}








#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{

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


    char clientbuf[128];
    char buf[128];

    for(;;)
    {
    write(1, "client: ", 8);
        fgets(clientbuf, 128, stdin);
        error = write(aSocket, clientbuf, strlen(clientbuf));

        if(error <= 0)
        {
            write(2, "ERR:write\n", 10);
            return 1;
        }

        for(int i = 0; i < 128; i++) clientbuf[i] = 0;

        error = read(aSocket, buf, 128);

        if(error <= 0)
        {
            write(2, "ERR:read\n", 9);
            return 1;
        }

        write(1, "server: ", 8);
        write(1, buf, strlen(buf));
       // write(1, "\n", 1);

        for(int i = 0; i < 128; i++) buf[i] = 0;
    }

    return 0;
}


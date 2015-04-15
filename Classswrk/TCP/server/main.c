#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>//sockaddrin struct
#include <unistd.h>// write and read
#include <string.h>
int main(void)
{
    int listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(listenSocket < 0)
    {
        write(2, "ERR:socket\n", 11);
        return 1;
    }

    int error; //code error
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(7500); //setevoi poriadok byt
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

    char buf[128];
    error = read(aSocket, buf, 128);

    if(error <= 0)
    {
        write(2, "ERR:read\n", 9);
        return 1;
    }

    write(1, buf, strlen(buf));
    write(1, "\n", 1);

    error = write(aSocket, " error: can't connection ", strlen(" error: can't connection "));

    if(error <= 0)
    {
        write(2, "ERR:read\n", 9);
        return 1;
    }

    return 0;
}


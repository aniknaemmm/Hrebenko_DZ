#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>//sockaddrin struct
#include <arpa/inet.h>//только для клиента
#include <unistd.h>// write and read
#include <string.h>
int main(int argc, char **argv)
{
    /**
     *  client
     * ------------
     * socet
     *   |
     * connect-server
     *   |
     * read/write
     */

    /**
     * server
     * ---------
     * socet
     *   |
     * blind-локально
     *   |
     * listen
     *   |
     * accept - client
     *   |
     * read/write
    */

    /**
     * находиться в <sys/socket.h>//seti
     * int socket (int domain,int type,int protocol);
     * 1)домен ( а)межпроцессорное (общение на одном компьютаре) б)сетевой домен(макрос AF_INET))
     * 2)тип TCP  use SOCK_STREAM
     * 3)протокол (по необходимости) а так 0
     * получаем дискриптор сокета если не получилось возрoшает -1
     *
     * int connect(int dSocket,const struct sockaddr *peer,int peer_len);
     * возрощает 0 если всё хорошо и -1 если всё плохо
     *
     * int bind(int dSocket,const struct sockaddr *name,int name_len);
     * возрощает 0 если всё хорошо и -1 если всё плохо
     * порт который будем прослушивать
     *
     * int listen( int dSocket, int backlog);
     * backlog сколькоможет слушать
     * возрощает 0 если всё хорошо и -1 если всё плохо
     *
     * int accept(int dSocket,struct sockaddr *addr,int *addr_len);
     * вернёт файловый дескриптор по которому сможем общаться с клиентом
     *
    */
    int aSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(aSocket < 0)
    {
        write(2, "ERR:socket\n", 11);
        return 1;
    }

    int error; //code error
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(7500); //setevoi poriadok byt
    peer.sin_addr.s_addr = inet_addr(argv[1]);

    error = connect(aSocket, (struct sockaddr *)&peer, sizeof(peer));

    if(error)
    {
        write(2, "ERR:connect\n", 12);
        return 1;
    }

    error = write(aSocket, "olalala",7);

    if(error <= 0)
    {
        write(2, "ERR:write\n", 10);
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

    return 0;
}


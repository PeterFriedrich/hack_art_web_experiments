// This program literally just makes a socket, then trys 
// to connect

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  // inet_addr

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    
    // IP address, Port number, AD family struct
    server.sin_addr.s_addr = inet_addr("35.197.7.135");
   // server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected"); // literally just connect
    return 0;
}

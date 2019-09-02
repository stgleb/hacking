#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "hacking.h"

/*
build: gcc simple_server.c -o simple_server

run: ./simple_server
*/

#define PORT 7890

const int BUFFER_SIZE = 1024;

int main() {
    // fd socket to listen
    int sockfd;
    // fd for new connections
    int new_sockfd;

    struct sockaddr_in host_addr;
    struct sockaddr_in client_addr;

    socklen_t sin_size;

    int recv_length=1;
    int yes = 1;

    char buffer[BUFFER_SIZE];

    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        exit(1);

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
        exit(2);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(host_addr.sin_zero), '\0', 8);

    if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
        exit(3);

    if(listen(sockfd, 5) == -1)
        exit(4);

    printf("start listening to %s:%d\n", inet_ntoa(host_addr.sin_addr),
                                       ntohs(host_addr.sin_port));
    while(1){
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
        if(new_sockfd == -1)
            exit(5);
        printf("server: got connection from %s port %d\n",
        inet_ntoa(client_addr.sin_addr),
        ntohs(client_addr.sin_port));
        send(new_sockfd, "Hello world!\n", 13, 0);
        recv_length = recv(new_sockfd, &buffer, BUFFER_SIZE, 0);

        while(recv_length > 0) {
            printf("RECV: %d bytes\n", recv_length);
            dump(buffer, recv_length);
            recv_length = recv(new_sockfd, &buffer, BUFFER_SIZE, 0);
        }
        close(new_sockfd);
    }

    return 0;
}
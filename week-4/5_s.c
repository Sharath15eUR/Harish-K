#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define port 8080
#define SIGINT 2
int serv_fd;
int new_socket;

void handler(int sig){
    close(serv_fd);
    close(new_socket);
    exit(0);
}

int main(){
    signal(SIGINT, handler);
    struct sockaddr_in serv, client;
    socklen_t addrlen = sizeof(client);
    char buffer[1024] = {0};
    int val;
    //creating a socket for server
    if((serv_fd=socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Cannot create a socket\n");
        exit(0);
    }
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_family = AF_INET;
    //binding the socket
    if(bind(serv_fd, (struct sockaddr*)&serv, sizeof(serv))<0){
        printf("Error while binding the socket");
        close(serv_fd);
        exit(0);
    }
    //listen
    if(listen(serv_fd, 3)<0){
        printf("Error while Listening...More than 3 ports connected");
        close(serv_fd);
        exit(0);
    }
    else{
        printf("Listening.....\n");
    }
    if((new_socket=accept(serv_fd, (struct sockaddr*)&client, &addrlen))<0){
        printf("Error while accepting the socket");
        close(serv_fd);
        exit(0);
    }
    val = read(new_socket, buffer, 1023);
    printf("The string is %s\n", buffer);
    int n = strlen(buffer);
    int i, j;
    for(i=0, j=n-1; i<n && j>=0; i++, j--){
        if(buffer[i]!=buffer[j]){
            char out[1] = {'1'};
            send(new_socket, out, 1, 0);
            close(new_socket);
            close(serv_fd);
            return 0;
        }
    }
    char out[1] = {'2'};
    send(new_socket, out, 1, 0);
    close(new_socket);
    close(serv_fd);
    return 0;
}
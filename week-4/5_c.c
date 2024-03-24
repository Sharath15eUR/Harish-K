#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define port 8080

int main(){
    int client_fd;
    //creating socket for client
    if((client_fd=socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Cannot create a socket\n");
        exit(0);
    }
    //connecting to the server
    struct sockaddr_in serv_addr;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_family = AF_INET;
    if((inet_pton(AF_INET,"127.0.0.1", &serv_addr.sin_addr))<0){
        printf("Not a valid address\n");
        close(client_fd);
        exit(0);
    }
    int status;
    if((status= connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)))<0){
        printf("Connection failed");
        exit(0);
    }
    //sending and receiving from client
    char buffer[1024], out[1];
    printf("Enter the  string: ");
    scanf("%s", buffer);
    send(client_fd, buffer, strlen(buffer), 0);
    read(client_fd, out, 1);
    if(out[0]=='1')
    printf("It is not a palindrome\n");
    else
    printf("It is palindrome\n");
    close(client_fd);

}
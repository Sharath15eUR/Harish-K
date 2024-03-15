#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int flag=0;

void *func1(void *vargp){
    printf("Hello ");
    flag=1;
    return NULL;
}

void *func2(void *vargp){
    while(flag==0);
    printf("World");
}

void main(){
    pthread_t tid_1;
    pthread_t tid_2;
    
    pthread_create(&tid_1, NULL, func1, NULL);
    pthread_create(&tid_2, NULL, func2, NULL);
    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);
}
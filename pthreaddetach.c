#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX 100

static void * threadFunc(void *arg){
    char *s = (char *)arg;
    int count = 0;
    printf("Thread: threadFunc started\n");
    
    pthread_detach(pthread_self());  //this line prevents the thread from becoming a zombie thread
    for(count=0; count<MAX; count++);

    sleep(5);
    printf("\nThread: threadFunc Exiting Now\n");
}

int main(int argc, char *argv[]){
    pthread_t t1_id;
    void *res;
    int s;
    s = pthread_create(&t1_id, NULL, threadFunc, NULL);  
    if(s != 0){
        perror("Thread creation failed");
    } 

    printf("Main thread: Exiting Now\n");
    pthread_exit(NULL);
}


// Output=>
/*
/Sysprg$ gcc pthreaddetach.c -lpthread -o pthreaddetach
harold@Haroldgodwinson:/mnt/c/Users/sankh/Documents/Sysprg$ ./pthreaddetach
Main thread: Exiting Now
Thread: threadFunc started

Thread: threadFunc Exiting Now
*/



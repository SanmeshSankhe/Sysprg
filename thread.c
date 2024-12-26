#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void * threadFunc(void *arg){
    char *str = (char *)arg;
    printf("ThreadFunc: arguments passes to thread are: %s, pid = (%d)\n", str, getpid());
    (void)sleep(2);
    printf("\nThreadFunc: Exiting Now\n");
    return(0);
}

int main(int argc, char *argv[]){
    pthread_t t1;
    void *res;
    int s;
    s = pthread_create(&t1, NULL, threadFunc, "Hello World");
    if(s != 0){
        perror("Thread creation failed");
    }  
    printf("main thread: Message from main(), pid = (%d)\n", getpid());

    sleep(5);
    printf("\nmain thread: Exiting Now\n");

    exit(0);
}

/*
Output=>
/Sysprg$ gcc thread.c -lpthread -o thread
harold@Haroldgodwinson:/mnt/c/Users/sankh/Documents/Sysprg$ ./thread
main thread: Message from main(), pid = (3638)
ThreadFunc: arguments passes to thread are: Hello World, pid = (3638)
ThreadFunc: Exiting Now

main thread: Exiting Now
*/
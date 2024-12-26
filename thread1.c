#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void * threadFunc(void *arg){
    char *str = (char *)arg;
    printf("ThreadFunc: arguments passes to thread are: %s, pid = (%d)\n", str, getpid());
    (void)sleep(15);
    printf("\nThreadFunc: Exiting Now\n");
    pthread_exit(0);
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

    // exit(0);
    pthread_exit(0);
}

/*
Here main thread will complete its execution and exit before the threadFunc() completes its execution.
so here defunct thread will be created.

/Sysprg$ gcc thread1.c -lpthread -o thread1
/Sysprg$ ./thread1
main thread: Message from main(), pid = (3661)
ThreadFunc: arguments passes to thread are: Hello World, pid = (3661)

main thread: Exiting Now

ThreadFunc: Exiting Now
*/


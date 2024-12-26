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
    
    while(1){
        sleep(1);
        printf("\nThreadFunc: executing loop\n"); 
    }

    sleep(5);
    printf("\nThread: threadFunc Exiting Now\n");
}

int main(int argc, char *argv[]){
    pthread_t t1_id;
    void *res;
    int s, count;
    
    printf("Main thread started\n");
    s = pthread_create(&t1_id, NULL, threadFunc, NULL);  
    if(s != 0){
        perror("Thread creation failed");
    } 

    for (count = 0; count < 10; count++){
        sleep(5);
        printf("\n Main thread: count value = (%d)\n", count);
    }
    pthread_cancel(t1_id);  //cancelling the thread after 10 seconds
    // when you are unsure about the thread execution time, then you can cancel the thread after certain time.

    printf("Main thread: Exiting Now\n");
    pthread_exit(NULL);
}

/*
/Sysprg$ gcc pthreadcancel.c -lpthread -o pthreadcancel
harold@Haroldgodwinson:/mnt/c/Users/sankh/Documents/Sysprg$ ./pthreadcancel
Main thread started
Thread: threadFunc started

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (0)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (1)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (2)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (3)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (4)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (5)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (6)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (7)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (8)

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

ThreadFunc: executing loop

 Main thread: count value = (9)
Main thread: Exiting Now
*/
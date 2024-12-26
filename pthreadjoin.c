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
    for(count=0; count<MAX; count++);

    sleep(5);
    printf("\nThread: threadFunc Exiting Now\n");
    if (count < 500){
        return((void *) " count < 500 ");
    }else{
        return((void *) " count > 500 ");
    }    
}

int main(int argc, char *argv[]){
    pthread_t t1_id;
    void *res;
    int s;
    s = pthread_create(&t1_id, NULL, threadFunc, NULL);  
    if(s != 0){
        perror("Thread creation failed");
    } 

#if 1
    s = pthread_join(t1_id, &res);
    if(s != 0)
        perror("Pthread_join error");
    printf("Main thread: Thread returned %s\n", (char *)res);
#endif

    printf("Main thread: Exiting Now\n");
    pthread_exit(NULL);
}

// Output=>
/*
/Sysprg$ gcc pthreadjoin.c -lpthread -o pthreadjoin
/Sysprg$ ./pthreadjoin
Thread: threadFunc started

Thread: threadFunc Exiting Now
Main thread: Thread returned  count < 500
Main thread: Exiting Now
*/


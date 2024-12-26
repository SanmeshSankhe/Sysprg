// will help is to access critical section in atomic way

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);  //lock the critical section
    printf("\nEntered..\n");

    //critical section
    sleep(4);
    
    //signal
    printf("\nJust Exiting...\n");
    sem_post(&mutex); //unlock the critical section
}

int main(){
    sem_init(&mutex, 0, 1); //mutex used to locking/unlocking the critical section
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}


// Output:
/*
/Sysprg$ gcc sema_phore.c -lpthread -lrt -o sema_phore
harold@Haroldgodwinson:/mnt/c/Users/sankh/Documents/Sysprg$ ./sema_phore

Entered..

Just Exiting...

Entered..

Just Exiting...
*/
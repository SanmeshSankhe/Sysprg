#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT); // Create a shared memory segment of 1024 bytes with key 2345
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0); // Attach the shared memory segment to the process address space
    printf("Process attached at %p\n", shared_memory); 
    printf("Data read from shared memory is: %s\n", (char*)shared_memory);
}


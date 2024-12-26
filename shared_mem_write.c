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
    printf("Enter some data to write to the shared memory\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("You wrote: %s\n", (char*)shared_memory);
    return 0;
}

/*
/Sysprg$ gcc shared_mem_write.c -lrt -o shared_mem_write
/Sysprg$ gcc shared_mem_read.c -lrt -o shared_mem_read

/Sysprg$ ./shared_mem_write
Key of shared memory is 0
Process attached at 0x7f02c0d38000
Enter some data to write to the shared memory
LINUXXXXXXX
You wrote: LINUXXXXXXX

/Sysprg$ ./shared_mem_read
Key of shared memory is 0
Process attached at 0x7fd17b095000
Data read from shared memory is: LINUXXXXXXX
*/

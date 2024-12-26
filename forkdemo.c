#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t id;
    printf("The ID of the parent Process is: %d\n", getpid());
    id = fork();
    if (id < 0){
        printf("Fork process creation has failed\n");
        exit(-1);
    }
    if (id > 0 ){
        printf("This is the parent process has created a child process with PID as : %d\n", id);
    }
    else{
        printf("\nThis is the child process with PID as : %d\n", id);
        printf("\n child process id by using getpid() function is as: %d\n", getpid());
        printf("\n parent process id  of this child is by using getppid() function is as: %d\n", getppid());
    }
    return 0;
}

/*
/Sysprg$ ./forkdemo
The ID of the parent Process is: 2715
This is the parent process has created a child process with PID as : 2716

This is the child process with PID as : 0

 child process id by using getpid() function is as: 2716

 parent process id  of this child is by using getppid() function is as: 2715
*/
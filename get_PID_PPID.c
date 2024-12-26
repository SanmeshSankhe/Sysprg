#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main (void)
{
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
}


/*
/Sysprg$ ./get_PID_PPID
PID: 2419
PPID: 504
*/




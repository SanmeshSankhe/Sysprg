#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    pid_t cpid;
    int status = 0;
    cpid = fork();
    if (cpid == -1){
        exit(-1);
    }
    if (cpid == 0){
        printf("The PID of the child process is: %d\n", getpid());
        sleep(25);
        printf("pritning the child process ID after sleep: %d\n", getpid());
        exit(1);  //exit status is 1 for child otherwise my child process will be in zombie state

    }else{
        printf("parent executing before wait()\n");
        cpid = wait(&status);
        // cpid =waitpid(cpid, &status, 0);
        printf("\n wait() in parent done\nParent pid = %d\n", getpid());
        printf("\ncpid returned is (%d)\n", cpid);
        printf("\nstatus returned is (%d)\n", status);
    }

    return 0;

}

/*
Output=>
/Sysprg$ ./proc_monitor
parent executing before wait()
The PID of the child process is: 2878
pritning the child process ID after sleep: 2878

wait() in parent done
Parent pid = 2877

cpid returned is (2878)

status returned is (256)
*/


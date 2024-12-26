#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int pfd[2];
    char buf[50] = {};
    ssize_t numRead;
    if (pipe(pfd) == -1)
        exit(-1);

    switch (fork()){
        case -1:
            exit(-1);

        case 0: //child

            if (close(pfd[1]) == -1) //close writing end of pipe
                exit(-1);
            
            for (;;){
                strcpy(buf, "");
                numRead = read(pfd[0], buf, 50);
                if (numRead == -1)
                    exit(-1);
                if (numRead == 0){
                    printf("\n Child : No write End Found\n");
                    break;
                }

                printf("\n Data received in child process is %s\n",buf);
        }
        if (close(pfd[0]) == -1)
            exit(-1);
        
        break;
    
    default: //parent
        if(close(pfd[0]) == -1)  //close reading end of pipe
            exit(-1);
        
        printf("\nParent: sending the following Data to Child - %s\n", argv[1]);
        write(pfd[1], argv[1], strlen(argv[1]));
        sleep(2);
            if (close(pfd[1]) == -1)
                exit(-1);
        printf("\n Parent: closing writing FD of pipe\n");
        wait(NULL);
        exit(0);    

}
}

/*
/Sysprg$ ./pipe_wrkng_btw_parent_child HaroldgodwinsonKKKKK

Parent: sending the following Data to Child - HaroldgodwinsonKKKKK
 Data received in child process is HaroldgodwinsonKKKKK
 Parent: closing writing FD of pipe
 Child : No write End Found
*/



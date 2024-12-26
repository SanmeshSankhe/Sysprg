#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char buff[50];
    char data[50]={};
    
    if (pipe(fd) == -1)
    {
        perror(" error: pipe");
        exit(1);
    }

    sprintf(buff, "PIPEeee dataaaa exampleee");

    write(fd[1], buff, strlen(buff)); // write data to pipe // write end of pipe is fd[1]
    printf("\n");

    read(fd[0], data, 5); // read end of pipe is fd[0]
    printf("%s\n", data);

    read(fd[0], data, 5);
    printf("%s\n", data);
    
    read(fd[0], data, 10);
    printf("%s\n", data);    
}


/*
Output:
/Sysprg$ ./pipes
PIPEe
ee da
taaaa exam
*/
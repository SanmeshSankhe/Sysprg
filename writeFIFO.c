#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char arr2[80];

    mkfifo(myfifo, 0660);
    
    fd = open(myfifo, O_WRONLY);

    while(1)
    {
        printf("\n Enter the data to be sent via FIFO: \n");
        fgets(arr2, 80, stdin);

        write(fd, arr2, strlen(arr2)+1); //to write the input from user to FIFO
    }
    close(fd);
    return 0;
}


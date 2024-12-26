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
    char str1[80];
    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0660);
    
    fd = open(myfifo, O_RDONLY);

    while(1)
    {
        read(fd, str1, 80);
        printf("\n Data received from FIFO is: %s\n", str1);
    }
    close(fd);
    return 0;
}



mqd_t mq_close(mqd_t mqdes);
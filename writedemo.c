#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int sz;
    char buf[100];

    strcpy(buf, "GGGG HHHH JJJJ LLLLL IIIII OOOOO \n ");
    int fd = open("xyz.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);  //O_APPEND is used to append the data in the file
    //O_trunc is used to overwrite the data in the file

    if (fd < 0) {
        perror("r1");
        exit(1);
    }

    sz = write(fd, buf, strlen(buf));

    printf("number of bytes written to the file are as:%d\n" , sz);
}


/*
/Sysprg$ gcc writedemo.c -o writedemo
/Sysprg$ ./writedemo
number of bytes written to the file are as:35
*/



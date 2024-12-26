#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(){
    int fd, i;
    char buf[100];
    char buf2[2] = {'\n'};

    fd = open("/mnt/c/Users/sankh/Documents/Sysprg/log.txt", O_RDWR | O_SYNC);  // O_SYNC is a flag that tells the kernel to write the data to disk immediately. This is useful for programs that need to guarantee that the data is written to disk before continuing.

    for (i = 0; i < 99; i++){
        buf[i] = 'a';
    }

    for(i = 0; i < 100; i++){
        write(fd, buf, 99);
        write(fd, buf2, 1);
    }
    printf("Program1 has written to log.txt\n");
    close(fd);

}
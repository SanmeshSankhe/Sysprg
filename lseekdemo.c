#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int sz, seek_pos=0;
    char buf[200];

    int fd = open("demo.c", O_RDWR);  
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    seek_pos = lseek(fd, 5, SEEK_SET); // SEEK_SET is used to set the file pointer to the beginning of the file

    sz= read(fd, buf, 10);
    buf[sz] = '\0'; // Null terminate the buffer
    printf("The data that is read from the file is as:%s\n", buf);

    seek_pos = lseek(fd, 0, SEEK_END); // SEEK_END is used to set the file pointer to the end of the file
    strcpy(buf, "I have added thi line using Lseek function with SEEK_SET");
    sz = write(fd, buf, strlen(buf));

    close(fd);
return 0;
}

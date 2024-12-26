#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    int fd, sz;
    char buf[100] = {0};

    fd = open("demo.c", O_RDONLY);

    if (fd < 0) {
        perror("Error in opening file");
        exit(1);
    }

    sz = read(fd, buf, 18); // here we read 18 bytes from the file

    printf("The data read from the file is as: \n%s", buf);

}

/*
/Sysprg$ gcc readdemo.c -o readdemo
/Sysprg$ ./readdemo
The data read from the file is as:
#include <stdio.h>
*/


#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
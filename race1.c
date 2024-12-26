#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd; 
    
    fd = open("/mnt/c/Users/sankh/Documents/Sysprg/log.txt", O_RDWR);
    perror("open failed");
    if(fd < 0){
        sleep(5);
        fd = open("/mnt/c/Users/sankh/Documents/Sysprg/log.txt", O_RDWR | O_CREAT, 0666);
        if(fd > 0){
            printf("\nProgram1 has created log.txt\n");
            close(fd);
        }
    }
    
}

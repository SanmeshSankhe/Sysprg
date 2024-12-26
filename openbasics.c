#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd;
    fd = open("demo.c", O_RDONLY | O_CREAT , S_IRUSR | S_IWUSR); 
    //if file is not present then it will create the file S_IRUSR and S_IWUSR are the permissions for the file
    if (fd == -1)
    {
        printf("Error in opening file\n");
        return 1;
    }
    else
    {
        printf("File opened successfully\n");
    }
    
    return 0;
}


/*   
/Sysprg$ gcc openbasics.c -o openbasics

/Sysprg$ ./openbasics

File opened successfully
*/


#include <unistd.h>
ssize_t write(int fd, void *buffer, size_t count);
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    pid_t id;
    id = fork();
    printf("Hellp world it's linux\n");

    return 0;
}

/*
Output:
/Sysprg$ ./fork_easy
Hellp world it's linux 
Hellp world it's linux 
// This line is printed twice because the fork() function creates a child, and both parent and child processes continue to execute the code after the fork() function.
*/

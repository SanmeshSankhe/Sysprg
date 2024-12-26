#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    pid_t cpid;
    cpid = fork();
    if(cpid == -1){
        exit(-1);
    }   

    if(cpid == 0){
        printf("Child: before exec\n");
        execl("./exec2", "arg1", "arg2", NULL);
        printf("\n Child: line is not printed\n");

    }else{
        printf("I am parent Process");
    }

return 0;
}


/*
/Sysprg$ gcc exec1.c -o exec1
/Sysprg$ gcc exec2.c -o exec2
/Sysprg$ ./exec1
I am parent Process
Child: before exec
 Hello, I am the second Program
*/

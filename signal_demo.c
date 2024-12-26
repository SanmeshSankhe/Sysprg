#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

static void signal_handler(int signo){
    if(signo == SIGINT){
        printf("Caught SIGINT\n");
    }
    else if(signo == SIGTERM){
        printf("Caught SIGTERM\n");
    }
   exit (EXIT_SUCCESS);
}


int main(){

    printf("\n Process ID is(%d)\n", getpid());

    if(signal(SIGINT, signal_handler) == SIG_ERR){
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(-1);
    }
    if(signal(SIGTERM, signal_handler) == SIG_ERR){
        fprintf(stderr, "Cannot handle SIGTERM\n");
        exit(-1);
    }
    while(1);
}


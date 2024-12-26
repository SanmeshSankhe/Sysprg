#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void display_message(int s){
    printf("Alarm clock signal received\n");
    signal(SIGALRM, SIG_DFL);
    //signal(SIGALRM, SIG_IGN);

    alarm(2);
}

int main(){
    signal(SIGALRM, display_message);
    alarm(2);
    while(1);
}




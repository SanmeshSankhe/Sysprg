#include<time.h>
#include<stdio.h>

void function_time(){
    printf(" The Process has started!\n");
    printf("Press any key to stop execution of process!\n");
    for(;;){
        if(getchar()){
            break;
        }
    }
    printf("Function has stopped...The Process has ended!\n");
}

int main(){
    clock_t t;
    t = clock();
    function_time();
    t = clock() - t;

    double time_taken_by_func = ((double)t)/CLOCKS_PER_SEC;
    printf("The function took %f seconds processing time to execute\n", time_taken_by_func);
}


// Output:
/*
/Sysprg$ gcc processtime.c -o processtime
harold@Haroldgodwinson:/mnt/c/Users/sankh/Documents/Sysprg$ ./processtime
 The Process has started!
Press any key to stop execution of process!
l
Function has stopped...The Process has ended!
The function took 0.000126 seconds processing time to execute
*/
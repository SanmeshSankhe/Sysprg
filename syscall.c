#include <stdio.h>
#include <unistd.h> //to perform write syscall
#include <string.h> // to perform string operations

int main() {
    size_t length;
    int lenString;
    char buf[100];  //create a buffer array to store the string

    strncpy(buf, "Hello!, I am priting from syscall\n", 99); //copy the string to the buffer
    lenString = strlen(buf); //get the length of the string

    length = write(1,buf,lenString); //write the string to the standard output

    return 0;

}






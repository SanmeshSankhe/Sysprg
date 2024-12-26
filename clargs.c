#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    if(argc==1) // name of the program is also considered as 1 command line argument
    {
        printf("Please provide command Line argument!!!\n");
        return 0;
    }
    else
    {
        printf("Command line arguments are - %d are they are\n\n", argc);
        for(i=0;i<argc;i++)
        {
            printf("%d-%s \n", i+1 ,argv[i]);
        }
        return 0;
    }
}

/*
/Sysprg$ ./clargs hello my name is harold JJJ KKKK LLLLL
Command line arguments are - 9 are they are
1-./clargs
2-hello
3-my
4-name
5-is
6-harold
7-JJJ
8-KKKK
9-LLLLL
*/
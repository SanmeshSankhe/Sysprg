#include <stdlib.h>
#include <stdio.h>

void main (void)
{
    // int *p = calloc(sizeof(int));
    // *p = 10;
    // printf("%d\n", *p);
    // free(p);
    int *p = NULL; 

    p = (int *)calloc(10 , sizeof(int));

    if (p == NULL){
        printf("Memory allocation failed\n");
        exit(-1);
    }
  
    for (int x=0; x<10; x++){
        p[x] = x;
    }
    
    for (int x=0; x<10; x++){
        printf("\npint[%d] = (%d)",x,p[x]);
    }

    free(p);
}

/*
Output:
/Sysprg$ ./calloc

pint[0] = (0)
pint[1] = (1)
pint[2] = (2)
pint[3] = (3)
pint[4] = (4)
pint[5] = (5)
pint[6] = (6)
pint[7] = (7)
pint[8] = (8)
pint[9] = (9)
*/
#include <stdio.h> 
#include "args_check.h"

void check_args(int argc, char* argv[]) 
{
    int i=0;
    for (; i < argc; i++) {
        // 0th argument is the name of this program.
        // arg 0: ./app. 
        printf("arg %d: %s\n", i, argv[i]); 
    }
}


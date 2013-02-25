#include <stdio.h>
#include <stdlib.h>

typedef char ByteArray[8];

int get_sizeof(int param[]);

int main(int argc, char* argv[])
{
    ByteArray ar;
    printf("ar is at 0x%x\n", (int)ar);
   
    int int_arr[] = {1,2,3,4,5};

    // int size * 5 
    printf("size as array: %d\n", sizeof(int_arr));

    // sizeof parameter is size of pointer itself. 
    // in 32-bit os, it should be 4.
    // check http://stackoverflow.com/a/10349610/534701
    printf("size as param: %d\n", get_sizeof(int_arr));
    return EXIT_SUCCESS;
error:
    return EXIT_FAILURE;
}

int get_sizeof(int param[]) {
    return sizeof(param);
}

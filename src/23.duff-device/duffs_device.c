#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duffs_device(char* from, char* to, size_t count)
{
    int i = 0;
    for (i = 0; i < count; i++) {
        *to++ = *from++;
    }
    
}

int main(int argc, char* argv[])
{
    char from[1000] = {'a'};    //from[0]= 97, from[1]= 0
    char to[1000] = {'c'};
    int rc = 0;
    
    // memset is byte-based operative function
    memset( from, 'x', 
            1000*sizeof(char)); //from[0]= 120, from[1]= 120, ...
    
    duffs_device(from, to, 10);
    printf("char size(%d): %02d %02d", sizeof(char), to[0], to[1]);
                                //to[0]= 120, to[1]= 120, ...

    return EXIT_SUCCESS;
}

#include <stdio.h>

int main(void) 
{
    int ages[] = { 20, 10, 30, 40, 45 };
    char* names[] = { 
        "Alex", "Nephilim", 
        "Doortts", "Npcode", "Cocobruni" };

    // various string exist in the same distance 
    // with its neighbor
    int count = sizeof(ages)/sizeof(int);
    int i = 0;
    for (i = 0; i < count; i ++) {
        printf("%s@address(%ld) - age(%d)\n", 
                *(names + i), (names + i), *(ages + i));
    }

    // pointer + 1 
    // add one "address unit"
    char** cur_name = names;
    for (;(cur_name - names) < count; cur_name++)
    {
        printf("name: %s\n",*cur_name);
    }
    return 0;
}

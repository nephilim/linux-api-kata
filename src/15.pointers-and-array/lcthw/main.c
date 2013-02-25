#include <stdio.h>

int main(void) 
{
    char* names[] = { 
        "Alex", "Nephilim", 
        "Doortts", "Npcode", "Cocobruni" };
    int ages[] = { 20, 10, 30, 40, 45 };
    double double_ages[] = { 20.0, 10.0, 25.0, 40.0, 45.0};
    
    // size comparison
    printf("size of ages: %d, size of double_ages: %d\n", sizeof(ages), sizeof(double_ages));

    // change first elems if ages
    // *ages = 30;

    // various string exist in the same distance 
    // with its neighbor
    int count = sizeof(ages)/sizeof(int);

    int i = 0;
    for (i = 0; i < count; i ++) {
        printf("%s@address(%ld) - age(%d)\n", 
                *(names + i), (names + i), *(ages + i));
    }

    printf("1[names] also works like this: %s\n", 1[names]);
    printf("strchr: 'e' on 'Alex' located at (0x%x/0x%x)\n", names[0], strchr(names[0], 'e'));
    // pointer + 1 
    // add one "address unit"
    char** cur_name = names;
    for (;(cur_name - names) < count; cur_name++)
    {
        printf("name: %s\n",*cur_name);
    }
    return 0;
}

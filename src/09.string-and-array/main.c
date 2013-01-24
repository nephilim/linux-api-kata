#include <stdio.h>
int main(int argc, char* argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};
    char* atog = "abcdefg";

    printf("numbers: %d %d %d %d\n",    // 0 0 0 0
            numbers[0], numbers[1],
            numbers[2], numbers[3]);
    printf("name: %c %c %c %c\n",       // a
            name[0], name[1],
            name[2], name[3]);

    name[0] = 'L';
    name[1] = 'e';
    name[2] = 'e';
    name[3] = '\0';

    printf("name (after init): %c %c %c %c\n",       // L e e
            name[0], name[1],
            name[2], name[3]);
    printf("as a string: %s\n", name);               // Lee

    char* another_name = "Kim";
    printf("another_name: %s\n", another_name);

    printf("another_name: %c %c %c %c\n",       // a
            another_name[0], another_name[1],
            another_name[2], another_name[3]);
    printf("size of another_name: %d\n", sizeof(another_name)/sizeof(char));
    
    name[0] = 'P';
    name[1] = 'a';
    name[2] = 'r';
    name[3] = 'k';

    printf("name (no zero end): %c %c %c %c\n",       // P a r k
            name[0], name[1],
            name[2], name[3]);
    printf("name[4] = %c\n", name[4]);
    printf("as a string: %s\n", name);

    return 0;
}


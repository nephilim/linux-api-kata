#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    greet();
    printf("greet: %p\n", &greet);
    return EXIT_SUCCESS;
}

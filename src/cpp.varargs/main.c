#include <stdio.h>
#include <stdlib.h>

#define va(c, d, ...) c(d, __VA_ARGS__)
#define var(a, b, ...) va(__VA_ARGS__, a, b)

int main(void)
{
    var(2,3, printf, "%d %d %d\n", 1);
    return EXIT_SUCCESS;
}


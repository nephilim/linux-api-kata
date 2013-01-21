#include <stdio.h>
#include "plus.h"

int main(int argc, char** argv) {
    int a = 1;
    int b = 2;
    printf("%d + %d = %d\n", a, b, plus(a,b));
}


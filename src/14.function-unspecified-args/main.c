#include <stdio.h>
#include <stdlib.h>

// forward declaration
// args **unspecified**
int echo_plus();     

/**
 * K&R Style function definition)
 */
int minus(a, b)
    int a;
    int b;
{
    return a-b;
}

int main( int argc, char** argv) 
{
    // following calls are successful
    // because args are not specied in its declaration
    echo_plus(3, 4, 5);
    echo_plus("PLUS()");

    // even a function declared in K&R style
    // you can also call them like followings
    printf("5 - 3 = %d\n", minus(5, 3));
    printf("5 - 4 = %d\n", minus(5, 4, 3, 2, 1));

    // so, you can put function with different args
    // in a array of function pointer 
    int (*fn[])() = { echo_plus, minus };
    fn[0]("echo_plus");
    printf("10 - 8 = %d", fn[1](10, 8));
    
    return EXIT_SUCCESS;
}

int echo_plus() 
{
    printf("plus() called\n");
    return EXIT_SUCCESS;
}



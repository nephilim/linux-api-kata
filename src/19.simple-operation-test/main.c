#include <stdio.h>
#include <stdlib.h>

int process_input() 
{
    printf("> ");
    char input = getchar();
    getchar();  // pass ENTER

    switch(input) {
        case -1:
            printf("exit!\n");
            return 0;
            break;
        case 't':
            printf("test\n");
            break; 
        default:
            printf("%02d\n", input);
    }
    return 1;
}

int main(void) 
{
    while( process_input() ) {
    }
    return EXIT_SUCCESS;
}

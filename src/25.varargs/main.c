#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_DATA 100
#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__) 
#define check(C, M, ...) if(!(C)) { log_error(M, ##__VA_ARGS__); }


//calloc vs malloc
//realloc 
int read_scan(const char* format, ...)
{
    // va_list = char*
    va_list argp;
    va_start(argp, format);
    
    /* int arg = va_arg(argp, int); */
    /* printf("arg1: %d\n", arg); */
    
    //TODO: null terminating varargs
    char* arg;
    while((arg = va_arg(argp, char*)) != NULL) 
    {
        printf("arg: %s\n", arg);
    }
    va_end(argp);
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    char* first_name = NULL;
    /* int (*main_ptr)() = main; */
    /* printf("main: 0x%x\n", (int)&main_ptr); */
    
    printf("first name: 0x%x\n", (int)&first_name);
    
    read_scan("hello", "10", "20", "30", "100", "200", "300", NULL);

    check(first_name == NULL, "first name should be null");
    return EXIT_SUCCESS;

error:
    return EXIT_FAILURE;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define check(C, M, ...) if(!(C)) { log_error(M, ##__VA_ARGS__); errno = 0; goto error;} 

void first_method(void);
void second_method(void);

int main(int argc, char* argv[]) 
{
    //array[row] = *(array + row)
    //first_method();
    second_method();
    return EXIT_SUCCESS;
error:
    return EXIT_FAILURE;
}

void first_method(void)
{
    int rows = 5, cols = 5;
    typedef int RowArray[cols];
    RowArray* multi;    // int (ptr)[5]
    multi  = malloc(rows * cols * sizeof(int));

    check( multi != NULL, "memory allocation failure" );
    
    for (int row=0; row < rows; row++)
    {
        for(int col=0; col < cols; col++)
        {
            multi[row][col] = 1;
        }
    }

    printf("1: [5,5] %d\n", multi[4][4]);

    // what should be wrong?
    free(multi);

error:
    return;
}

void second_method(void)
{
    int rows = 5, cols = 10;
    int (*multi)[10] = malloc(rows * cols * sizeof(int));
    check( multi != NULL, "memory allocation failed" );
    
    printf( "2: size %d\n",  sizeof(multi) );
    
    printf( "0x%x\n", (int)multi);
    printf( "0x%x\n", (int)(multi+1));  // +40
    
    for (int row=0; row<rows; row++) {
        for (int col=0; col<cols; col++) {
            multi[row][col] = 1;
    }}

    
    printf("2: [5,10] %d\n", multi[4][9]);
error:
    return;
}

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#define MAX_DATA 100
#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d error:%s) " M "\n", __FILE__, __LINE__, strerror(errno), ##__VA_ARGS__);
#define check(C, M, ...) if (!(C)) { log_error(M, ##__VA_ARGS__); errno=0; goto error; }
#define FILE_NAME "sample.dat"

int main(int argc, char* argv[])
{
   //check(access(FILE_NAME, F_OK) != -1, "File %s should exist.", FILE_NAME); 
   FILE* file = fopen(FILE_NAME, "w+");

   //rewind(file);
   fseek(file, 0L, SEEK_SET); 
   
   for (int i = 0; i < 3; i++ ) {
       printf("input something: ");

       // int array initialize
       // char* pVar; assert( pVar != NULL );
       char data[MAX_DATA];
       char* input = fgets(data, MAX_DATA, stdin);
       // TODO: get rid of 0x0a at the end of string
       check(input != NULL, "Input Error.");
       printf("strlen of '%s': %d\n", input, strlen(input)); 
       int wc = fwrite(data, sizeof(data), 1, file);   
       check(wc == 1, "Write count should be 1, but it is %d", wc);
   }
   fclose(file);

   // TODO: check the content of 'sample.dat' with od -s (not working) or od -t x1z -A x...
   return EXIT_SUCCESS;

error:
   return EXIT_FAILURE;
}

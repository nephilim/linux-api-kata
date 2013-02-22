#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 10

// __VA_ARGS__ -> ##__VA_ARGS__
#define error_msg() (errno == 0 ? "None": strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errorno: %s) " M "\n", __FILE__, __LINE__, error_msg(), ##__VA_ARGS__)

#define check(CONDITION, M, ...) if (!(CONDITION)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

typedef enum _EyeColor {
    BLUE,
    GREEN,
    BROWN,
    BLACK,
    OTHER
} EyeColor;


typedef struct _Person {
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    int age;
    EyeColor eye_color;
} Person;


int main(int argc, char* argv[])
{
    Person person = {.age = 0};
    char* in = NULL;

    //
    printf("first name? ");
    in = fgets(person.first_name, MAX_DATA, stdin);
    check(in != NULL, "Failed to read first name");

    // never use gets
    // gets(person.first_name);
    
    // don't do followings (it spit out the enter later)
    //fscanf(stdin, "%20s", person.first_name);
    //printf("first name is %s", person.first_name);

    //
    printf("last name? ");
    in = fgets(person.last_name, MAX_DATA, stdin);
    check(in != NULL, "Failed to read last name");

    //
    printf("What is your " "age? ");
    int life_expectation =0;

    // fscanf returns read count
    int rc = fscanf(stdin, "%d", &person.age);
    check(rc > 0, "You have to enter a number");

    //
    printf("color of eye? ");
    
    return EXIT_SUCCESS;

error:
    return EXIT_FAILURE;
}

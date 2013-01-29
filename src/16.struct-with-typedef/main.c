#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 
struct _Person;
typedef struct _Person Person;

Person* create_person(char*, int);
void destroy_person(Person*);
void print_person(Person*);

int main(int argc, char** argv)
{
    Person* me = create_person("Daniel", 38);
    print_person(me);
    destroy_person(me);
    return 0;
}

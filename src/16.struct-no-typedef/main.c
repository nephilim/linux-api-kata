#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Person;
struct Person* create_person(char*, int);
void destroy_person(struct Person*);
void print_person(struct Person*);

int main(int argc, char** argv)
{
    struct Person* me = create_person("Daniel", 38);
    print_person(me);
    destroy_person(me);
    return 0;
}

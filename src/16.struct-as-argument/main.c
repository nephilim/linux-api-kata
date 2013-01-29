#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Person 
{
    char* name;
    int age;
} Person;

void edit_person(Person person)
{
    person.name = "Edited";
    person.age = 10;
}

void print_person(Person person)
{
    printf("name: %s\n", person.name);
    printf("age: %d\n", person.age);
}

int main(int argc, char** argv)
{
    Person me;
    me.name = "Daniel";
    me.age = 38;

    print_person(me);
    // 'me' is copied into edit_person
    // so there would be no change.
    edit_person(me);
    print_person(me);

    return 0;
}



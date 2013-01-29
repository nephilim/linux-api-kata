#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "person.h"

Person* create_person(char* name, int age)
{
    Person* person = malloc(sizeof(Person));
    assert(person != NULL);

    person->name = strdup(name);
    person->age = age;
    return person;
}
    
void print_person(Person* person)
{
    assert(person != NULL);

    printf("name: %s\n", person->name);
    printf("age: %d\n", person->age);
}

void destroy_person(Person* person)
{
    assert(person != NULL);
    
    free(person->name);
    free(person);
}

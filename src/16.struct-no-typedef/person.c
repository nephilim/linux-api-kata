#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "person.h"

struct Person* create_person(char* name, int age) 
{
    struct Person* person = malloc(sizeof(struct Person));
    person->name = strdup(name);
    person->age = age;

    return person;
}

void destroy_person(struct Person* person)
{
    assert(person != NULL);
    free(person->name);
    free(person);
}

void print_person(struct Person* person)
{
    assert(person != NULL);
    printf("name: %s\n", person->name);
    printf("age: %d\n", person->age);
}

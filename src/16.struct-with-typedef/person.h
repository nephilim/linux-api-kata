#ifndef __PERSON_H__
#define __PERSON_H__

struct _Person {
    char* name;
    int age;
};

typedef struct _Person Person;

Person* create_person(char* name, int age);
void print_person(Person* person);
void destroy_person(Person* person);

#endif

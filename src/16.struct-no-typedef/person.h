#ifndef __PERSON_H__
#define __PERSON_H__

struct Person 
{
    char* name;
    int age;
};

struct Person* create_person(char*, int);
void destroy_person(struct Person*);
void print_person(struct Person*);

#endif

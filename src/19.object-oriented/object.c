#include <stdio.h>
#include "object.h"

void object_destroy(void* self)
{
    Object* obj = self;
    if(obj) {
        if(obj->description) {
            free(obj->description);
            free(obj);
        }
    }
}

void object_describe(void* self)
{
    Object* obj = self;
    printf("%s.\n", obj->description);
}

int object_init(void* self)
{
    return 1;
}

void* object_move(void* self, Direction direction)
{
    printf("you can't move right now\n");
    return NULL;
}

int object_attack(void* self, int damage)
{
    printf("you can't attack righrt now\n");
    return 0;
}

void* object_new(size_t size, Object proto, char* description)
{
    if(!proto.init) proto.init = object_init;
    if(!proto.describe) proto.describe = object_describe;
    if(!proto.destroy) proto.destroy = object_destroy;
    if(!proto.attack) proto.attack = object_attack;
    if(!proto.move) proto.move = object_move;

    Object *el = calloc(1, size);
    *el = proto;

    el->description = strdup(description);
    if(!el->init(el)) {
        // it's not properly initialized
        el->destroy(el);
        return NULL;
    } else {
        return el;
    }
}

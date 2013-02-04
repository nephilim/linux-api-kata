#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct _Object {
    char*   description;
    int     (*init)(void* self);
    int     (*destroy)(void* self);
    void    (*describe)(void* self);
    void*   (*move)(void *self, Direction direction);
    int     (*attack)(void *self, int damage);
} Object;

int     object_init(void* self);
void    object_destroy(void* self);
void    object_describe(void* self);
void*   object_move(void* self, Direction direction);
int     object_attack(void* self, int damage);
void*   object_new(size_t size, Object proto, char* description);

#define NEW(T, N)
object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N
#endif

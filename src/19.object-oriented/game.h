#ifndef __GAME_H__
#define __GAME_H__

#include "object.h"

typedef struct _Monster {
    Object proto;
    int hit_points;
} Monster;

int monster_attack(void* self, int damage);
int monster_init(void* self);

typedef struct _Room {
    Object proto;
    Monster* monster;

    Room* north;
    Room* south;
    Room* east;
    Room* west;
} Room;

void* room_move(void* self, Direction direction);
int room_attack(void* self, int damage);
int room_init(void* self);

typedef struct _Map {
    Object proto;
    Room* start;
    Room* location;
} Map;

void* map_move(void* self, Direction direction);
int map_attack(void* self, int damage);
int map_init(void* self);

#endif

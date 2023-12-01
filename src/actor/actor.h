#ifndef ACTOR_H
#define ACTOR_H

typedef enum { AT_ACTOR, AT_SNAKE, AT_SPEEDYSNAKE, AT_SIZE } ActorType;
typedef enum {
  DIRECTION_UP,
  DIRECTION_RIGHT,
  DIRECTION_LEFT,
  DIRECTION_DOWN,
  DIRECTION_SIZE
} Direction;

typedef struct position {
  char x;
  char y;
} Position;

typedef struct {
  Direction direction;
  Position pos;
  ActorType type;
} Actor;

typedef struct {
  Actor actor;
  char size;
} Snake;

typedef struct {
  Actor actor;
  char size;
  char speed;
} SpeedySnake;

void *actor_create(ActorType t);
int actor_change_direction(Actor *actor, Direction dir);
int actor_move(Actor *actor);
int actor_grow(Actor *actor);

#endif

#ifndef ACTORTYPESINTERNAL_H
#define ACTORTYPESINTERNAL_H

typedef enum { AT_ACTOR, AT_SNAKE, AT_SPEEDYSNAKE, AT_COUNT } ActorType;
typedef enum {
  DIRECTION_UP,
  DIRECTION_RIGHT,
  DIRECTION_LEFT,
  DIRECTION_DOWN,
  DIRECTION_COUNT
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

typedef void ActorHandler;

#endif

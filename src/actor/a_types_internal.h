#ifndef ATYPESINTERNAL_H
#define ATYPESINTERNAL_H

typedef enum { AT_ACTOR, AT_SNAKE, AT_SPEEDYSNAKE, AT_COUNT } ActorType;
typedef enum {
  DIRECTION_UP,
  DIRECTION_RIGHT,
  DIRECTION_LEFT,
  DIRECTION_DOWN,
  DIRECTION_COUNT
} Direction;

typedef struct {
  unsigned int x;
  unsigned int y;
} Position;

typedef struct {
  Direction direction;
  Position pos;
  const ActorType type;
} Actor;

typedef struct {
  Actor actor;
  char size;
} Snake;

typedef struct {
  Actor actor;
  char size;
  float speed;
} SpeedySnake;

typedef void ActorHandler;

#endif

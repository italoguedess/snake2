#include "actor.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void *actor_create(ActorType t) {
  void *object = NULL;
  switch (t) {
  case AT_ACTOR:
    object = malloc(sizeof(Actor));
    break;
  case AT_SNAKE:
    object = malloc(sizeof(Snake));
    ((Snake *)object)->actor.type = AT_SNAKE;
    break;
  case AT_SPEEDYSNAKE:
    object = malloc(sizeof(SpeedySnake));
    ((SpeedySnake *)object)->actor.type = AT_SPEEDYSNAKE;
    ((SpeedySnake *)object)->speed = 5;
  }

  return object;
}

int actor_change_direction(Actor *actor, Direction dir) {
  actor->direction = dir;
  return 0;
}

int actor_move(Actor *actor) {
  // setting the actor speed
  float speed =
      (actor->type == AT_SPEEDYSNAKE) ? ((SpeedySnake *)actor)->speed : 1;

  // the speed can't be negative
  assert(speed > 0);
  if (actor->direction == DIRECTION_UP) {
    actor->pos.y += speed;
  } else if (actor->direction == DIRECTION_RIGHT) {
    actor->pos.x += speed;
  } else if (actor->direction == DIRECTION_LEFT) {
    actor->pos.x += speed;
  } else if (actor->direction == DIRECTION_DOWN) {
    actor->pos.y += speed;
  }
  return 0;
}

int actor_grow(Actor *actor) {
  // actor only grows if it is a Snake or a SpeedySnake
  switch (actor->type) {
  case AT_SNAKE:
    ((Snake *)actor)->size++;
    break;
  case AT_SPEEDYSNAKE:
    ((SpeedySnake *)actor)->size++;
    break;
  default:
    return 1;
  }
  return 0;
}

#include "actor.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

ActorHandler *actor_create(ActorType t) {
  ActorHandler *object = NULL;
  switch (t) {
  case AT_ACTOR:
    object = malloc(sizeof(Actor));
    ((Snake *)object)->actor.type = AT_ACTOR;
    break;
  case AT_SNAKE:
    object = malloc(sizeof(Snake));
    ((Snake *)object)->actor.type = AT_SNAKE;
    ((Snake *)object)->size = 1;
    break;
  case AT_SPEEDYSNAKE:
    object = malloc(sizeof(SpeedySnake));
    ((SpeedySnake *)object)->actor.type = AT_SPEEDYSNAKE;
    ((SpeedySnake *)object)->size = 1;
    ((SpeedySnake *)object)->speed = 5;
    break;
  default:
    assert("A non defined Actor Type was selected" && 0);
  }

  return object;
}

int actor_move(ActorHandler *actor) {
  // convert to Actor type
  Actor *A_actor = ((Actor *)actor);

  // setting the actor speed
  char speed =
      (A_actor->type == AT_SPEEDYSNAKE) ? ((SpeedySnake *)actor)->speed : 1;

  if (A_actor->direction == DIRECTION_UP) {
    A_actor->pos.y += speed;
  } else if (A_actor->direction == DIRECTION_RIGHT) {
    A_actor->pos.x += speed;
  } else if (A_actor->direction == DIRECTION_LEFT) {
    A_actor->pos.x += speed;
  } else if (A_actor->direction == DIRECTION_DOWN) {
    A_actor->pos.y += speed;
  }
  return 0;
}

int actor_grow(ActorHandler *actor) {
  Actor *A_actor = ((Actor *)actor);
  // if actor is a SpeedySnake increases its size and returns 0
  // otherwise returns -1
  switch (A_actor->type) {
  case AT_SNAKE:
    ((Snake *)A_actor)->size++;
    break;
  case AT_SPEEDYSNAKE:
    ((SpeedySnake *)A_actor)->size++;
    break;
  default:
    return -1;
  }
  return 0;
}

int actor_set_direction(ActorHandler *actor, Direction dir) {
  ((Actor *)actor)->direction = dir;
  return 0;
}

int actor_get_direction(ActorHandler *actor) {
  return ((Actor *)actor)->direction;
}

int actor_set_speed(ActorHandler *actor, char speed) {
  // the speed can't be negative
  assert(speed > 0);

  // if actor is a SpeedySnake changes its speed and returns 0
  // otherwise returns -1
  if (((Actor *)actor)->type == AT_SPEEDYSNAKE)
    ((SpeedySnake *)actor)->speed = speed;
  else
    return -1;

  return 0;
}

int actor_get_speed(ActorHandler *actor) {
  // if actor is a SpeedySnake returns its speed
  // otherwise returns -1
  if (((Actor *)actor)->type == AT_SPEEDYSNAKE)
    return ((SpeedySnake *)actor)->speed;
  else
    return -1;
}

int actor_set_size(ActorHandler *actor, int size) {
  // size can't be negative
  assert(size > 0);

  // if actor is a Snake or SpeedySnake returns sets its size and return 0
  // otherwise returns -1
  switch (((Actor *)actor)->type) {
  case AT_SNAKE:
    ((Snake *)actor)->size = size;
  case AT_SPEEDYSNAKE:
    ((SpeedySnake *)actor)->size = size;
  default:
    return -1;
  }
  return 0;
  
}

int actor_get_size(ActorHandler *actor) {
  switch (((Actor *)actor)->type) {
  case AT_SNAKE:
    return ((Snake *)actor)->size;
  case AT_SPEEDYSNAKE:
    return ((SpeedySnake *)actor)->size;
  default:
    break;
  }
  return -1;
}

int actor_set_position(ActorHandler *actor, Position pos) {
  assert("In the grid there are no negative positions" && pos.x >= 0 && pos.y >= 0);
  ((Actor *)actor)->pos.x = pos.x;
  ((Actor *)actor)->pos.y = pos.y;
  return 0;
  
}

Position actor_get_position(ActorHandler *actor) {
  Actor *A_actor = (Actor *)actor;
  return (Position){A_actor->pos.x, A_actor->pos.y};
}

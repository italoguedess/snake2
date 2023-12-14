#include "actor.h"
#include "a_types_internal.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ActorHandler *actor_create(ActorType t) {
  ActorHandler *object = NULL;
  switch (t) {
  case AT_ACTOR: {
    object = malloc(sizeof(Actor));
    Actor temp = {DIRECTION_UP, (Position){0, 0}, AT_ACTOR};
    memcpy(object, &temp, sizeof(temp));
    break;
  }

  case AT_SNAKE: {
    object = malloc(sizeof(Snake));
    Snake temp = {(Actor){DIRECTION_UP, (Position){0, 0}, AT_SNAKE}, 1};
    memcpy(object, &temp, sizeof(temp));
    break;
  }

  case AT_SPEEDYSNAKE: {
    object = malloc(sizeof(SpeedySnake));
    SpeedySnake temp = {(Actor){DIRECTION_UP, (Position){0, 0}, AT_SPEEDYSNAKE},
                        1, 5};
    memcpy(object, &temp, sizeof(temp));
  } break;
  default:
    assert("A non defined Actor Type was selected" && 0);
  }

  return object;
}

void actor_move(ActorHandler *actor) {
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
}

void actor_grow(ActorHandler *actor) {
  Actor *A_actor = ((Actor *)actor);
  // if actor is a SpeedySnake increases its size
  // otherwise does nothing
  switch (A_actor->type) {
  case AT_SNAKE:
    ((Snake *)A_actor)->size++;
    break;
  case AT_SPEEDYSNAKE:
    ((SpeedySnake *)A_actor)->size++;
    break;
  default:
    assert("This actor type cannot grow" && 0);
    break;
  }
}

void actor_destroy(ActorHandler *actor) { free(actor); }

void actor_direction_set(ActorHandler *actor, Direction dir) {
  ((Actor *)actor)->direction = dir;
}

int actor_direction_get(ActorHandler *actor) {
  return ((Actor *)actor)->direction;
}

void actor_speed_set(ActorHandler *actor, char speed) {
  // the speed can't be negative
  assert(speed > 0);

  // if actor is a SpeedySnake changes its speed and returns 0
  // otherwise returns -1
  if (((Actor *)actor)->type == AT_SPEEDYSNAKE)
    ((SpeedySnake *)actor)->speed = speed;
  else
    assert("This actor type does not have a speed attribute" && 0);
}

int actor_speed_get(ActorHandler *actor) {
  // if actor is a SpeedySnake returns its speed
  // otherwise returns -1
  if (((Actor *)actor)->type == AT_SPEEDYSNAKE)
    return ((SpeedySnake *)actor)->speed;
  else
    assert("This actor type does not have a speed attribute" && 0);
}

void actor_size_set(ActorHandler *actor, int size) {
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
    assert("This actor type does not have a size attribute" && 0);
  }
}

int actor_size_get(ActorHandler *actor) {
  switch (((Actor *)actor)->type) {
  case AT_SNAKE:
    return ((Snake *)actor)->size;
  case AT_SPEEDYSNAKE:
    return ((SpeedySnake *)actor)->size;
  default:
    assert("This actor type does not have a size attribute" && 0);
    break;
  }
}

void actor_position_set(ActorHandler *actor, Position pos) {
  assert("In the grid there are no negative positions" && pos.x >= 0 &&
         pos.y >= 0);
  ((Actor *)actor)->pos.x = pos.x;
  ((Actor *)actor)->pos.y = pos.y;
}

Position actor_position_get(ActorHandler *actor) {
  Actor *A_actor = (Actor *)actor;
  return (Position){A_actor->pos.x, A_actor->pos.y};
}

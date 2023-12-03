#ifndef ACTOR_H
#define ACTOR_H

#include "actor_types_internal.h"

/* actor interface */

ActorHandler* actor_create(ActorType t);
int actor_move(ActorHandler *actor);
int actor_grow(ActorHandler *actor);
int actor_set_direction(ActorHandler *actor, Direction dir);
int actor_get_direction(ActorHandler *actor);
int actor_set_speed(ActorHandler *actor, char speed);
int actor_get_speed(ActorHandler *actor);
int actor_set_size(ActorHandler *actor, int size);
int actor_get_size(ActorHandler *actor);
int actor_set_position(ActorHandler *actor, Position pos);
Position actor_get_position(ActorHandler *actor);

#endif

#ifndef ACTOR_H
#define ACTOR_H
#include "a_types_internal.h"

/* actor interface */

/**
 * Creates an actor object according to an ActorType
 */
ActorHandler *actor_create(ActorType t);

/**
 * Moves actor if possible, throws an error if not
 */
void actor_move(ActorHandler *actor);

/**
 * Grows actor if possible, throws an error if not
 */
void actor_grow(ActorHandler *actor);

/**
 * Free actor object
 */
void actor_destroy(ActorHandler *actor);

/* getters and setters interface */
void actor_direction_set(ActorHandler *actor, Direction dir);
int actor_direction_get(ActorHandler *actor);
void actor_speed_set(ActorHandler *actor, char speed);
int actor_speed_get(ActorHandler *actor);
void actor_size_set(ActorHandler *actor, int size);
int actor_size_get(ActorHandler *actor);
void actor_position_set(ActorHandler *actor, Position pos);
Position actor_position_get(ActorHandler *actor);

#endif

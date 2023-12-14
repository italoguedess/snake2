#include "tests.h"
#include "../actor/actor.h"
#include <stdio.h>

// tests the direction and position moving of all actor types
void test_actor() {
  for (unsigned int i = 0; i < AT_COUNT; i++) {
    printf("************************ \n");
    printf("Testing actor of type %d! \n", i);
    void *actor = actor_create(i);

    printf("\n");
    printf("Initial direction %d \n", actor_direction_get(actor));
    actor_direction_set(actor, DIRECTION_LEFT);
    printf("New direction %d \n", actor_direction_get(actor));

    printf("\n");
    printf("Initial position (%d, %d) \n", actor_position_get(actor).x,
           actor_position_get(actor).y);
    actor_move(actor);
    printf("Moved position (%d, %d) \n", actor_position_get(actor).x,
           actor_position_get(actor).y);
    actor_position_set(actor, (Position){5, 5});

    printf("Set position (%d, %d) \n", actor_position_get(actor).x,
           actor_position_get(actor).y);

    // AT_ACTOR does not have a size attribute
    if (i != AT_ACTOR) {
      printf("\n");
      printf("Initial size %d \n", actor_size_get(actor));
      actor_grow(actor);
      printf("New size %d \n", actor_size_get(actor));
    }

    // Only AT_SPEEDYSNAKE has a speed attribute
    if (i == AT_SPEEDYSNAKE) {
      printf("\n");
      printf("Speed %d \n", actor_speed_get(actor));
      actor_destroy(actor);
    }
  }

  /* printf("************************ \n"); */
  /* printf("Testing non existent actor type %d! \n", -1); */
  /* actor_create(-1); */

  /* printf("************************ \n"); */
  /* printf("Testing invalid actor positioning (%d, %d)! \n", -1, -1); */
  /* void *actor = actor_create(AT_ACTOR); */
  /* actor_position_set(actor, (Position){-1, -1}); */
}

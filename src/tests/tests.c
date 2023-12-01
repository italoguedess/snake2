#include "tests.h"
#include "../actor/actor.h"
#include <stdio.h>

// tests the direction and position moving of all actor types 
void test_actor() {
  for (unsigned int i = 0; i < AT_SIZE; i++) {
    printf("************************ \n");
    printf("Testing actor of type %d! \n", i);
    Actor *actor = actor_create(i);

    printf("\n");
    printf("Initial direction %d \n", actor->direction);
    actor_change_direction(actor, DIRECTION_LEFT);
    printf("New direction %d \n", actor->direction);

    printf("\n");
    printf("Initial position (%d, %d) \n", actor->pos.x, actor->pos.y);
    actor_move(actor);
    printf("New position (%d, %d) \n", actor->pos.x, actor->pos.y);

    if (i == AT_SNAKE) {
      printf("\n");
      printf("Initial size %d \n", ((Snake *)actor)->size);
      actor_grow(actor);
      printf("New size %d \n", ((Snake *)actor)->size);
      
    }

    if (i == AT_SPEEDYSNAKE) {
      printf("\n");
      printf("Initial size %d \n", ((SpeedySnake *)actor)->size);
      actor_grow(actor);
      printf("New size %d \n", ((SpeedySnake *)actor)->size);

      printf("\n");
      printf("Speed %d \n", ((SpeedySnake *)actor)->speed);
      
    }
  }
}

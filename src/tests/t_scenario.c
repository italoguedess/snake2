#include "../scenario/scenario.h"
#include "tests.h"
#include <stdio.h>

void test_scenario() {

  printf("************************ \n");
  printf("Testing scenario module: \n");
  printf("************************ \n");
  for (unsigned int i = 0; i < ST_COUNT; i++) {
    void *scenario = scenario_create(i);

    printf("\n");
    printf("Scenario bounds are: [%d. %d] \n", ((Scenario *)scenario)->bounds.x,
           ((Scenario *)scenario)->bounds.y);

    printf("Passing the position: [%d. %d] \n",
           ((Scenario *)scenario)->bounds.x, ((Scenario *)scenario)->bounds.y);

    printf("Results in: %d \n",
           scenario_check_bounds(scenario,
                                 (Position){((Scenario *)scenario)->bounds.x,
                                            ((Scenario *)scenario)->bounds.y}));

    printf("Passing the position: [%d. %d] \n",
           ((Scenario *)scenario)->bounds.x + 1,
           ((Scenario *)scenario)->bounds.y + 1);

    printf("Results in: %d \n",
           scenario_check_bounds(
               scenario, (Position){((Scenario *)scenario)->bounds.x + 1,
                                    ((Scenario *)scenario)->bounds.y + 1}));

    scenario_destroy(scenario);
  }
}

#include "scenario.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

ScenarioHandler *scenario_create(ScenarioType t) {
  void *object = NULL;
  switch (t) {
  case ST_SCENARIO:
    object = malloc(sizeof(Scenario));
    Scenario temp = {(Position){255, 255}, ST_SCENARIO};
    memcpy(object, &temp, sizeof(temp));
    break;
  default:
    assert("Invalid Scenario type" && 0);
  }

  return object;
}

int scenario_check_bounds(ScenarioHandler *scenario, Position pos) {
  // if the given position is greater than bounds or lesser than 0
  // returns -1, otherwise returns 0
  if ((pos.x > ((Scenario *)scenario)->bounds.x || pos.x < 0) ||
      (pos.y > ((Scenario *)scenario)->bounds.x || pos.y < 0)) {
    return -1;
  }

  return 0;
}

void scenario_destroy(ScenarioHandler *scenario) { free(scenario); }
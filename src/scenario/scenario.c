#include "scenario.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

ScenarioHandler *scenario_create(ScenarioType t) {
  void *object = NULL;
  switch (t) {
  case ST_SCENARIO:
    object = malloc(sizeof(Scenario));
    Scenario temp = {(Position){800, 450}, ST_SCENARIO};
    memcpy(object, &temp, sizeof(temp));
    break;
  default:
    assert("Invalid Scenario type" && 0);
  }

  return object;
}

int scenario_bounds_check(ScenarioHandler *scenario, Position pos) {
  // Checks bounds accordingly to raylib positioning
  if ((pos.x > ((Scenario *)scenario)->bounds.x || pos.x < 0) ||
      (pos.y < -((Scenario *)scenario)->bounds.y || pos.y > 0)) {
    return -1;
  }

  return 0;
}

void scenario_destroy(ScenarioHandler *scenario) { free(scenario); }

Position scenario_bounds_get(ScenarioHandler *scenario) {
  return ((Scenario *)scenario)->bounds;
}

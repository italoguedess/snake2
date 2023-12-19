#ifndef SCENARIO_H
#define SCENARIO_H

#include "../actor/actor.h"

typedef enum { ST_SCENARIO, ST_COUNT } ScenarioType;

typedef struct {
  const Position bounds;
  const ScenarioType type;
} Scenario;

typedef void ScenarioHandler;

/**
 * Creates a scenario object according to a ScenarioType
 */
ScenarioHandler *scenario_create(ScenarioType t);

/**
 * Checks if the given position is inside the given Scenario bounds
 *
 * @return 0 if true -1 if false
 */
int scenario_bounds_check(ScenarioHandler *scenario, Position pos);

/**
 * Free Scenario object memory
 */
void scenario_destroy(ScenarioHandler *scenario);

Position scenario_bounds_get(ScenarioHandler *scenario);

#endif

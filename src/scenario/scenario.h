#ifndef SCENARIO_H
#define SCENARIO_H

typedef enum { ST_SCENARIO, ST_COUNT } ScenarioType;

typedef struct {
  char x;
  char y;
} Bounds;

// This is valid since Bounds and Position are modeled the same way
typedef Bounds Position;

typedef struct {
  Bounds bounds;
  ScenarioType type;
} Scenario;

typedef void ScenarioHandler;
typedef void ActorHandler;

/**
 * Creates a scenario object according to a ScenarioType
 */
ScenarioHandler *scenario_create(ScenarioType t);

/**
 * Checks if the given position is inside the given Scenario bounds
 *
 * @return 0 if true -1 if false
 */
int scenario_check_bounds(ScenarioHandler *scenario, Position pos);

/**
 * Free Scenario object memory
 */
void scenario_destroy(ScenarioHandler *scenario);

#endif

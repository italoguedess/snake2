#ifndef GAME_H
#define GAME_H

#include "g_types_internal.h"
#include <stddef.h>

/**
 * Creates a game object according to a GameType
 */
GameHandler *game_create(GameType t);

void game_state_toggle(GameHandler *game);
void game_loop(GameHandler *game);

/**
 * Free game object
 */
void game_destroy(GameHandler *game);

ActorHandler *game_actor_get(GameHandler *game);
void game_actor_set(GameHandler *game, ActorHandler* actor);
ScenarioHandler *game_scenario_get(GameHandler *game);
void game_scenario_set(GameHandler *game, ScenarioHandler* scenario);
DrawerHandler *game_drawer_get(GameHandler *game);
void game_drawer_set(GameHandler *game, DrawerHandler *drawer);
GameState game_state_get(GameHandler *game);
void game_state_set(GameHandler *game, GameState gs);
GameScreenType game_screen_type_get(GameHandler *game);
void game_screen_type_set(GameHandler *game, GameScreenType gst);
size_t game_screen_width_get(GameHandler *game);
void game_screen_width_set(GameHandler *game, size_t size);
size_t game_screen_height_get(GameHandler *game);
void game_screen_height_set(GameHandler *game, size_t size);

#endif

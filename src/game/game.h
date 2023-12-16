#ifndef GAME_H
#define GAME_H

#include "g_types_internal.h"

/**
 * Creates a game object according to a GameType
 */
GameHandler *game_create(GameType t);

void game_start(GameHandler *game);
void game_pause(GameHandler *game);
void game_loop(GameHandler *game);

/**
 * Free game object
 */
void game_destroy(GameHandler *game);

ActorHandler *game_actor_get();
void game_actor_set();
ScenarioHandler *game_scenario_get();
void game_scenario_set();
MenuHandler *game_menu_get();
void game_menu_set();
GameState game_state_get();
void game_state_set();
GameScreen game_screen_get();
void game_screen_set();

#endif

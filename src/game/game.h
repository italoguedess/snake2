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

ActorHandler *game_actor_get(GameHandler *game);
void game_actor_set(GameHandler *game, ActorHandler* actor);
ScenarioHandler *game_scenario_get(GameHandler *game);
void game_scenario_set(GameHandler *game, ScenarioHandler* scenario);
MenuHandler *game_menu_get(GameHandler *game);
void game_menu_set(GameHandler *game, MenuHandler *menu);
GameState game_state_get(GameHandler *game);
void game_state_set(GameHandler *game, GameState gs);
GameScreen game_screen_get(GameHandler *game);
void game_screen_set(GameHandler *game, GameScreen gsc);

#endif

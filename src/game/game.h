#ifndef GAME_H
#define GAME_H

typedef void ActorHandler;
typedef void ScenarioHandler;
typedef void MenuHandler;
typedef void GameHandler;

typedef enum { GT_GAME, GT_COUNT } GameType;
typedef enum { GS_PAUSED, GS_PLAYING, GS_COUNT } GameState;
typedef enum {
  GSC_LOGO,
  GSC_TITLE,
  GSC_GAMEPLAY,
  GSC_ENDING,
  GSC_COUNT
} GameScreen;

typedef struct {
  ActorHandler *Actor;
  ScenarioHandler *Scenario;
  MenuHandler *Menu;
  GameState state;
  GameScreen screen;
} Game;

/**
 * Creates a game object according to an GameType
 */
GameHandler *game_create(GameType t);

void game_start(GameHandler *game);
void game_pause(GameHandler *game);
void game_loop(GameHandler *game);

/**
 * Free actor object
 */
void game_destroy(GameHandler *game);

#endif

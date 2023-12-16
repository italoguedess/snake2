#ifndef GTYPESINTERNAL_H
#define GTYPESINTERNAL_H

typedef void ActorHandler;
typedef void ScenarioHandler;
typedef void MenuHandler;
typedef void GameHandler;

typedef enum { GT_DEBUG, GT_COUNT } GameType;
typedef enum { GS_PAUSED, GS_PLAYING, GS_COUNT } GameState;
typedef enum {
  GSC_LOGO,
  GSC_TITLE,
  GSC_GAMEPLAY,
  GSC_ENDING,
  GSC_COUNT
} GameScreen;

typedef struct {
  ActorHandler *actor;
  ScenarioHandler *scenario;
  MenuHandler *menu;
  GameState state;
  GameScreen screen;
} Game;

#endif

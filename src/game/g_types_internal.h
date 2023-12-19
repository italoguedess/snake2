#ifndef GTYPESINTERNAL_H
#define GTYPESINTERNAL_H

typedef void ActorHandler;
typedef void ScenarioHandler;
typedef void DrawerHandler;
typedef void GameHandler;

typedef enum { GT_GAME, GT_COUNT } GameType;
typedef enum { GS_PAUSED, GS_PLAYING, GS_COUNT } GameState;
typedef enum {
  GST_LOGO,
  GST_TITLE,
  GST_GAMEPLAY,
  GST_ENDING,
  GST_COUNT
} GameScreenType;

typedef struct {
  unsigned int screen_width;
  unsigned int screen_height;
  GameState state;
  GameScreenType screen;
  ActorHandler *actor;
  ScenarioHandler *scenario;
  DrawerHandler *drawer;
  GameType type;
} Game;

#endif

#include "game.h"
#include "../actor/actor.h"
#include "../scenario/scenario.h"
#include "../drawer/drawer.h"
#include "g_types_internal.h"
#include "raylib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GameHandler *game_create(GameType t) {
  void *object = NULL;
  switch (t) {
  case GT_DEBUG:
    object = malloc(sizeof(Game));
    Game *game = (Game *)object;
    game->actor = actor_create(AT_ACTOR);
    game->scenario = scenario_create(ST_SCENARIO);
    game->drawer = drawer_create(DT_DRAWER);
    game->state = GS_PLAYING;
    game->screen = GSC_LOGO;
    break;
  default:
    assert("This game type does not exist" && 0);
  }
  return object;
}

void game_state_toggle(GameHandler *game) {
  game_state_set(game, ~game_state_get(game));
}

void game_loop(GameHandler *game) {
  const int screenWidth = scenario_bounds_get(game_scenario_get(game)).x;
  const int screenHeight = scenario_bounds_get(game_scenario_get(game)).y;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - basic screen manager");

  GameScreen currentScreen = GSC_LOGO;

  int framesCounter = 0; // Useful to count frames

  SetTargetFPS(60); // Set desired framerate (frames-per-second)

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    switch (game_screen_get(game)) {
    case GSC_LOGO: {
      // TODO: Update LOGO screen variables here!

      framesCounter++; // Count frames

      // Wait for 2 seconds (120 frames) before jumping to TITLE screen
      if (framesCounter > 180) {
        game_screen_set(game, GSC_TITLE);
      }
    } break;
    case GSC_TITLE: {
      // TODO: Update GSC_TITLE screen variables here!

      // Press enter to change to GAMEPLAY screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        game_screen_set(game, GSC_GAMEPLAY);
      }
    } break;
    case GSC_GAMEPLAY: {
      // Checking for key presses
      if (IsKeyDown(KEY_A)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_LEFT);
      } else if (IsKeyDown(KEY_D)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_RIGHT);
      } else if (IsKeyDown(KEY_W)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_UP);
      } else if (IsKeyDown(KEY_S)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_DOWN);
      } else if (IsKeyDown(KEY_SPACE)) {
        game_state_toggle(game);
      }

      if (game_state_get(game) == GS_PLAYING) {
        actor_move(game_actor_get(game));
      }

      if (scenario_bounds_check(game_scenario_get(game),
                                actor_position_get(game_actor_get(game))) ==
          -1) {
        // end screen and actor resetting
        game_screen_set(game, GSC_ENDING);
        actor_position_set(game_actor_get(game), (Position){0, 0});
        actor_direction_set(game_actor_get(game), DIRECTION_RIGHT);
      }

      // Press enter to change to ENDING screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        printf("Game Screen: %d \n", game_screen_get(game));
        game_screen_set(game, GSC_ENDING);
      }
    } break;
    case GSC_ENDING: {
      // TODO: Update ENDING screen variables here!

      // Press enter to return to TITLE screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        game_screen_set(game, GSC_TITLE);
      }
    } break;
    default:
      break;
    }

    BeginDrawing();


    switch (game_screen_get(game)) {
    case GSC_LOGO: {
      // TODO: Draw GSC_LOGO screen here!
      drawer_draw_logo(game_drawer_get(game), screenWidth, screenHeight);

    } break;
    case GSC_TITLE: {
      // TODO: Draw GSC_TITLE screen here!
      DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
      DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
      DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20,
               DARKGREEN);

    } break;
    case GSC_GAMEPLAY: {
      // TODO: Draw GSC_GAMEPLAY screen here!
      // Draw the scenario
      DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
      // Draw the actor
      DrawRectangle(actor_position_get(game_actor_get(game)).x,
                    -actor_position_get(game_actor_get(game)).y, 40, 40, DARKGREEN);

    } break;
    case GSC_ENDING: {
      // TODO: Draw GSC_ENDING screen here!
      Vector2 f = MeasureTextEx(GetFontDefault(), "Game Over", 40, 1);
      DrawRectangle(0, 0, screenWidth, screenHeight, RED);
      DrawText("Game Over", (float)screenWidth / 2 - f.x / 2,
               (float)screenHeight / 2 - f.y, 40, BLACK);
      DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20,
               BLACK);

    } break;
    default:
      break;
    }

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------

  // TODO: Unload all loaded data (textures, fonts, audio) here!

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------
}

void game_destroy(GameHandler *game) {
  free(game_actor_get(game));
  free(game_scenario_get(game));
  free(game);
}

ActorHandler *game_actor_get(ActorHandler *game) {
  return ((Game *)game)->actor;
}

void game_actor_set(GameHandler *game, ActorHandler *actor) {
  memcpy(((Game *)game)->actor, actor, sizeof(actor));
}

ScenarioHandler *game_scenario_get(GameHandler *game) {
  return ((Game *)game)->scenario;
}

void game_scenario_set(GameHandler *game, ScenarioHandler *scenario) {
  memcpy(((Game *)game)->scenario, scenario, sizeof(scenario));
}

DrawerHandler *game_drawer_get(GameHandler *game) {
  return ((Game *)game)->drawer;
}

void game_drawer_set(GameHandler *game, DrawerHandler *drawer) {
  memcpy(((Game *)game)->drawer, drawer, sizeof(drawer));
}

GameState game_state_get(GameHandler *game) { return ((Game *)game)->state; }
void game_state_set(GameHandler *game, GameState gs) {
  ((Game *)game)->state = gs;
}

GameScreen game_screen_get(GameHandler *game) { return ((Game *)game)->screen; }

void game_screen_set(GameHandler *game, GameScreen gsc) {
  ((Game *)game)->screen = gsc;
}

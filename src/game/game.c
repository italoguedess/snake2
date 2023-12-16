#include "game.h"
#include "../actor/actor.h"
#include "../scenario/scenario.h"
#include "g_types_internal.h"
#include "raylib.h"
#include <assert.h>
#include <stdlib.h>

GameHandler *game_create(GameType t) {
  void *object = NULL;
  switch (t) {
  case GT_DEBUG:
    object = malloc(sizeof(Game));
    Game *game = (Game *)object;
    game->actor = actor_create(AT_ACTOR);
    game->scenario = scenario_create(ST_SCENARIO);
    game->state = GS_PLAYING;
    game->screen = GSC_LOGO;
    break;
  default:
    assert("This game type does not exist" && 0);
  }
  return object;
}

void game_start(GameHandler *game) { ((Game *)game)->state = GS_PLAYING; }

void game_pause(GameHandler *game) { ((Game *)game)->state = GS_PAUSED; }

void game_loop(GameHandler *game) {
  const int screenWidth = 800;
  const int screenHeight = 450;

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
    switch (currentScreen ){
    case GSC_LOGO: {
      // TODO: Update LOGO screen variables here!

      framesCounter++; // Count frames

      // Wait for 2 seconds (120 frames) before jumping to TITLE screen
      if (framesCounter > 120) {
        currentScreen = GSC_TITLE;
      }
    } break;
    case GSC_TITLE: {
      // TODO: Update GSC_TITLE screen variables here!

      // Press enter to change to GAMEPLAY screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        currentScreen = GSC_GAMEPLAY;
      }
    } break;
    case GSC_GAMEPLAY: {
      // TODO: Update GAMEPLAY screen variables here!

      // Checking for key press
      if (IsKeyDown(KEY_A)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_LEFT);
      } else if (IsKeyDown(KEY_D)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_RIGHT);
      } else if (IsKeyDown(KEY_W)) {
        actor_direction_set(((Game *)game)->actor, DIRECTION_UP);
      } else if (IsKeyDown(KEY_S)){
        actor_direction_set(((Game *)game)->actor, DIRECTION_DOWN);
      } else if (IsKeyDown(KEY_SPACE)){
	game_pause(game);
      }

      actor_move(((Game *)game)->actor);

      // Press enter to change to ENDING screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        currentScreen = GSC_ENDING;
      }
    } break;
    case GSC_ENDING: {
      // TODO: Update ENDING screen variables here!

      // Press enter to return to TITLE screen
      if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        currentScreen = GSC_TITLE;
      }
    } break;
    default:
      break;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (currentScreen) {
    case GSC_LOGO: {
      // TODO: Draw GSC_LOGO screen here!
      DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
      DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

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
      DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
      // Draw the actor
      DrawRectangle(actor_position_get(((Game *)game)->actor).x,
                    -actor_position_get(((Game *)game)->actor).y, 40, 40, RED);

    } break;
    case GSC_ENDING: {
      // TODO: Draw GSC_ENDING screen here!
      DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
      DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
      DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20,
               DARKBLUE);

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

void game_destroy(GameHandler *game) { free(game); }

#include "actor/actor.h"
#include "game/game.h"
#include "tests/tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  void* game = game_create(GT_GAME);
  game_loop(game);
  test_actor();
  
  return 0;
}

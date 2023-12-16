#include "actor/actor.h"
#include "game/game.h"
#include "tests/tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  void* game = game_create(GT_DEBUG);
  game_loop(game);
  return 0;
}

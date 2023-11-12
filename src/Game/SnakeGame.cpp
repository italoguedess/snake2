#include "SnakeGame.hpp"
#include <cstddef>

Level *SnakeGame::createLevel1(LevelBuilder &levelBuilder) {
  size_t numOfObstacles = 1;
  levelBuilder.BuildBounds();
  levelBuilder.BuildObstacles(numOfObstacles);

  return levelBuilder.getLevel();
}

#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include "../Level/Level.hpp"
#include "../Level/LevelBuilder.hpp"

class SnakeGame
{
public:
  Level* createLevel1(LevelBuilder& levelBuilder);
  SnakeGame();
  virtual ~SnakeGame();
};

#endif

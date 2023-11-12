#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Grid.hpp"
#include "Obstacle.hpp"

class Level {
public:
  Level();
  virtual ~Level();

  Grid* getGrid();
  Obstacle* getObstacles();
  void setGrid();
  void setObstacles();

private:
  Grid* bounds;
  Obstacle* obstacles;
};

#endif

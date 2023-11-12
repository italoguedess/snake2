#ifndef LEVELBUILDER_HPP
#define LEVELBUILDER_HPP

#include "Level.hpp"
#include <cstddef>

class LevelBuilder    
{
public:
  virtual void BuildLevel();
  virtual void BuildGrid();
  virtual void BuildObstacles(std::size_t n);
  virtual Level* getLevel();
protected:
  LevelBuilder();
  virtual ~LevelBuilder();
};

#endif

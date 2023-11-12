#ifndef STANDARDLEVELBUILDER_HPP
#define STANDARDLEVELBUILDER_HPP

#include "Level.hpp"
#include "LevelBuilder.hpp"
#include <cstddef>

class StandardLevelBuilder : public LevelBuilder
{
public:
  virtual void BuildLevel();
  virtual void BuildGrid();
  virtual void BuildObstacles(std::size_t n);
  virtual Level* getLevel();
protected:
  StandardLevelBuilder();
  virtual ~StandardLevelBuilder();
private:
  Level* _currentLevel;
};

#endif

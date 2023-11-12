#include "StandardLevelBuilder.hpp"
#include "Level.hpp"

StandardLevelBuilder::StandardLevelBuilder() {
  _currentLevel = nullptr;
}

void StandardLevelBuilder::BuildLevel() {
  _currentLevel = new Level;
}

void StandardLevelBuilder::BuildGrid() {
  
}

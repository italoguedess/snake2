#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include <cstddef>

class Grid {
public:
  Grid();
  virtual ~Grid();

private:
  std::array<std::array<std::size_t, 31>, 31> positions;
};

#endif

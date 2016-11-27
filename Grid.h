#ifndef GRID_H
#define GRID_H 1

#include <vector>

class Grid {
 public:
  Grid(int row = 18, int col = 11);
  Cell* getCell(int row, int col);
 private:
  std::vector grid <std::vector <Cell>>;
};

#endif

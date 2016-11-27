#ifndef GRID_H
#define GRID_H 1

#include <vector>

class Grid {
 public:
  Grid();
  Cell* getCell(int row, int col);
 private:
  std::vector grid <Cell>;
};

#endif

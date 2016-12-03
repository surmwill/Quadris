#include "Cell.h"
#include <vector>

class Grid{
 private:
  std::vector<std::vector<Cell>> grid;

 public:
  Grid(int row, int col);
  Cell * getCell(int row, int col);
};

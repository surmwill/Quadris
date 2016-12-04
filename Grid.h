#include "Cell.h"
#include "View.h"
#include <vector>

class Grid{
 private:
  std::vector<std::vector<Cell>> grid;

 public:
  Grid(const std::vector <View> & views, int row = 18, int col = 11);
  Cell * getCell(int row, int col);
};

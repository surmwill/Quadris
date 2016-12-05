#include "Cell.h"
#include "View.h"
#include "Observer.h"
#include <vector>

class Grid{
 private:
  std::vector<std::vector<Cell>> grid;

 public:
  Grid(const std::vector <View*> & views, Observer * score, int row = 18, int col = 11);
  Cell * getCell(int row, int col);
};

#include "Grid.h"
#include <vector>

using namespace std;

Grid::Grid() {
  for(int i = 0; i < 198; i++) {
    grid.emplace_back(new Cell{});
  }
}

Cell* Grid::getCell(int row, int col) {
}


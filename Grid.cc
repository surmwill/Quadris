#include "Grid.h"
#include <vector>

using namespace std;

Grid::Grid() {
  for(int i = 0; i < 18; i++) {
    for(int j = 0; j < 11; j++) {
      grid[i].emplace_back(new Cell{});
    }
  }
}

Cell* Grid::getCell(int row, int col) {
}

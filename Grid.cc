#include "Grid.h"
#include <vector>

using namespace std;

Grid::Grid(int row, int cols) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      grid[i].emplace_back(new Cell{});
    }
  }
}

Cell* Grid::getCell(int row, int col) {
}

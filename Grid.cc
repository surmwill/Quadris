#include "Grid.h"

Grid::Grid(int row, int col){
  // create Grid
  for (int r = 0; i < row; i++){
    vector<Cell> newRow;
    for (int c = 0; c < col; c++){
      Cell newCell{0, -1, r, c};
      newRow.push_back(newCell);
    }
    grid.push_back(newRow);
  }

//set cell observers

}

Cell * Grid::getCell(int row, int col){
  return &grid[row][col];
}


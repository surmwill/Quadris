#include "Grid.h"

using namespace std;

Grid::Grid(const vector <View*> & views, int row, int col){
  // create Grid
  for (int r = 0; r < row; r++){
    vector<Cell> newRow;
    for (int c = 0; c < col; c++){
      Cell newCell{0, -1, r, c};
      newRow.push_back(newCell);
    }
    grid.push_back(newRow);
  }

  // add neighbour Cells as observers
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      // Create Cells and set them to nullptr by default
      Cell * left = nullptr;
      Cell * right = nullptr;
      Cell * top = nullptr;
      Cell * bottom = nullptr;

      if (j > 0){
        left = &grid[i][j-1];
      }

      if (j < row){
        right = &grid[i][j+1];
      }

      if (i > 0){
        top = &grid[i-1][j];
      }

      if (i < col){
        bottom = &grid[i+1][j];
      }

      grid[i][j].setNeighbours(left, right, top, bottom);
      for(auto &v views) {
        grid[i][j].attachObserver(v);
      }
    }
  }
}

Cell * Grid::getCell(int row, int col){
  return &grid[row][col];
}


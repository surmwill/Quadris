#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid(const vector <View*> & views, Observer * score, int row, int col){
  vector <Cell> newRow;
  // create Grid
  for (int r = 0; r < row; r++){
    for (int c = 0; c < col; c++){
      Cell newCell{' ', 0 , -1, r, c};
      newRow.push_back(newCell);
    }
    grid.push_back(newRow);
    newRow.clear();
  }

  //A special cell used to notify the Views of what the next block is. Has coordinates (-1, -1)
  Cell specialCell{' ', -100, -100, -1, -1};
  for(auto &v: views) {
    specialCell.attach(v);
  }
  newRow.emplace_back(specialCell);
  grid.push_back(newRow);

  // add neighbour Cells as observers
  for (int r = 0; r < row; r++){
    for (int c = 0; c < col; c++){
      // Create Cells and set them to nullptr by default
      Cell * left = nullptr;
      Cell * right = nullptr;
      Cell * top = nullptr;
      Cell * bottom = nullptr;

      if (c > 0){
        left = &grid[r][c-1];
      }

      if (c < col-1){
        right = &grid[r][c+1];
      }

      if (r > 0){
        top = &grid[r-1][c];
      }

      if (r < row-1){
        bottom = &grid[r+1][c];
      }

      // add neighbours
      grid[r][c].setNeighbours(left, right, top, bottom);

      // add observers
      grid[r][c].attach(score);

      for(auto &v : views) {
        grid[r][c].attach(v);
      }
    }
  }
}

Cell * Grid::getCell(int row, int col){
  if(row == -1 && col == -1) return &grid[grid.size() - 1][0];
  else return &grid[row][col];
}

void Grid::reset() {
  for(unsigned int i = 0; i < grid.size() - 1; i++) {
    for(unsigned int j = 0; j < grid[i].size(); j++) {
      grid[i][j].unsetContent();
    }
  }
}

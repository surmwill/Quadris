#include "Grid.h"
#include <iostream>

#define DEBUG 1

using namespace std;

Grid::Grid(const vector <View*> & views, int row, int col){
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
  
  if(DEBUG) cout << "row " << row << "col " << col;

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

      grid[r][c].setNeighbours(left, right, top, bottom);
      for(auto &v : views) {
        grid[r][c].attach(v);
      }
    }
  }

  if(DEBUG == 1) cout << "Grid::Grid()" << endl;
}

Cell * Grid::getCell(int row, int col){
  if(row == -1 && col == -1) return &grid[grid.size() - 1][0];
  else return &grid[row][col];
}


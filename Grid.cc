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
      for(auto &v : views) {
        grid[i][j].attach(v);
      }
    }
  }

  if(DEBUG == 1) cout << "Grid::Grid()" << endl;
}

Cell * Grid::getCell(int row, int col){
  if(row == -1 && col == -1) return &grid[grid.size() - 1][0];
  else return &grid[row][col];
}


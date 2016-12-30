#include "Block.h"
#include <vector>
#include "Cell.h"
#include <iostream>
#include <cmath>
#include "Grid.h"

using namespace std;

Block::Block(vector <char> blockDesign, int levelGenerated, int blockSize) {
  blockLen = blockSize;
  for(auto bd:blockDesign) {
    // set the coordinates to (-1, -1) since the content will be taken and the cells discarded
    blockCells.emplace_back(new Cell{bd, blockSize, levelGenerated, -1, -1});
  }

}

Block::~Block(){}

bool Block::autoDrop(){
  return shouldDrop;
}

void Block::printBlockInfo() {
  for(unsigned int i = 0; i < blockCells.size(); i++) {
    cout << "cell: " << i << " row: " << blockCells[i]->getInfo().row << " col: " << blockCells[i]->getInfo().col << endl;
    if(blockCells[i]->getInfo().symbol != ' ') cout << "symbol : " << blockCells[i]->getInfo().symbol << endl;
   // cout << "set: " << blockCells[i]->getInfo().set << endl;  
  }
}

void Block::rotate(bool cc, int multi) {
  int blockDim = 4;
  vector <Cell*> temp;
  vector <vector <Cell*>> coords;
 
  printBlockInfo();
  
  for(int i = 0; i < blockDim; i++) {
    for(int j = 0; j < blockDim; j++) {
      temp.emplace_back(blockCells[i * blockDim + j]);
    }
    coords.emplace_back(temp);
    temp.clear();
  }

  Cell * pivotCell = coords[blockDim - 1][0];

  cout << "pivotX: " << pivotCell->getInfo().row << " pivotY: " << pivotCell->getInfo().col << endl;
  int toOriginX = pivotCell->getInfo().row;
  int toOriginY = pivotCell->getInfo().col;

  for(auto &n: coords) {
    for(auto &cell: n) {
      int cellRow = cell->getInfo().row;
      int cellCol = cell->getInfo().col;

      int newCellRow = cellRow;
      newCellRow -= toOriginX;
      newCellRow = cellCol;
      newCellRow += toOriginX;
      cell->setRow(newCellRow);  
 
      int newCellCol = cellCol;
      newCellCol -= toOriginY;
      newCellCol = cellRow;
      newCellCol += toOriginY;
      cell->setCol(newCellCol);

/*
      Cell newCell{' ', 0, -1};
      newCell.setContent(cell);
      newCell.setRow(newCellRow);
      newCell.setCol(newCellCol);
      cell->unsetContent();
*/
    }
  } 

  printBlockInfo();

/*
  for (int i = 0; i < blockLen; i++){
    for (int j = 0; j < blockLen; j++){
      // create new cell
      Cell newCell {' ', 0, -1}; // level set to -1, empty part of the block does not need level

      // Keep track of indices
      int currentIndex = (blockLen*i) + j;
      int oldLocation = (((blockLen*(blockLen - 1))+i) - (blockLen*j));
      if (cc){ oldLocation = (((blockLen*blockLen) - 1) - oldLocation); }

      // make sure that the rotation is valid
      if ((blockCells[oldLocation]->getInfo()).set){
        // if the destination of the cell at oldLocation is blocked, cancel rotation
        if (blockCells[currentIndex]->filled() && ((blockCells[currentIndex]->getInfo()).set)){
          return;
        }

        // set new cell content, fill current cell
        newCell.setContent(blockCells[oldLocation]);
      }

      // add the new cell to the rotated block
      rotatedBlock.push_back(newCell);
    }
  }

  // set the block cells to their rotated configuration
  for (int i = 0; i < blockLen; i++){
    blockCells[i]->setContent(&rotatedBlock[i]);
  }
*/
}

void Block::updateGridRotation(Grid * g) {
  for(auto &cell: blockCells) {
    int row = cell->getInfo().row;
    int col = cell->getInfo().col;
    cout << "row: " << row << " col: " << col << endl;

    g->getCell(row, col)->setContent(cell);
    cell = g->getCell(row, col);
  }
}

void Block::down(int multi){
  for(int i = 0; i < multi; i++) {
    if (canBeMoved(Direction::Down)){
      // move content starting from the bottom right of the block
      bool onBottom = false;
  
      for (int i = ((blockLen*blockLen) - 1); i >= 0; i--){
        // make sure we don't move the block off of the board
        Cell * newLocation = (blockCells[i]->drop());
        onBottom = (onBottom || (newLocation == nullptr));
        if (!onBottom){
          // point to new cell info location
          blockCells[i] = newLocation;
        }
      }
    } else {
      // mark the block as having been placed
      shouldDrop = true;
    }
  }
}

void Block::left(int multi) {
  for(int i = 0; i < multi; i++) {
    // if the cell can move left
    if (canBeMoved(Direction::Left)){
      // move content starting from the top left of the block
      bool onLeftEdge = false;

      for (int i = 0; i <= 15; i++){
        // make sure we don't move the block off of the board
        Cell * newLocation = (blockCells[i]->moveLeft());
        onLeftEdge = (onLeftEdge || (newLocation == nullptr));
        if (!onLeftEdge){
          // point to new cell info location
          blockCells[i] = newLocation;
        }
      }
    }
  }
}

void Block::right(int multi) {
  for(int i = 0; i < multi; i++) {
    // if the cell can move right
    if (canBeMoved(Direction::Right)){
      // move content starting from the bottom right of the block
      bool onRightEdge = false;

      for (int i = 15; i >= 0; i--){
        // make sure we don't move the block off of the board
        Cell * newLocation = (blockCells[i]->moveRight());
        onRightEdge = (onRightEdge || (newLocation == nullptr));
        if (!onRightEdge){
          // point to new cell info location
          blockCells[i] = newLocation;
        }
      }
    }
  }
}

bool Block::canBeMoved(Block::Direction d) {
  // get proper loop bounds to capture the right cells
  int step = 0;
  int start = 0;
  int end = 0;

  switch(d) {
    case (Direction::Down):
      // all bottom cells
      step = 1;
      start = (blockLen*(blockLen-1));
      end = (blockLen*blockLen);
      break;
    case (Direction::Left):
     // all leftmost cells
      step = blockLen;
      start = 0;
      end = ((blockLen*(blockLen-1)) + 1);
      break;
    case (Direction::Right):
     // all rightmost cells
      step = blockLen;
      start = blockLen-1;
      end = (blockLen*blockLen);
      break;
  }

  //check to see if the cells can move
  bool canBeMoved = true;
  for (int i = start; i < end; i += step){
    canBeMoved = (canBeMoved && movable(i, blockLen, d));
  }

  return canBeMoved;
}

bool Block::movable(int index, int cellsToCheck, Block::Direction d){
  // if there is no filled cell in this row or column
  if (cellsToCheck <= 0){
    return true;
  }

  // check movability
  if ((blockCells[index]->filled()) && (!(blockCells[index]->getInfo()).set)){
    if (d == Direction::Down){
      return blockCells[index]->droppable();
    } else if (d == Direction::Left){
      return blockCells[index]->movableLeft();
    } else if (d == Direction::Right){
      return blockCells[index]->movableRight();
    } else {
      //unknown direction
      return false;
    }
  } else {
    // set the step of Cells in the block
    int step = 0;
    if (d == Direction::Down){
      step = -4;
    } else if (d == Direction::Left){
      step = 1;
    } else if (d == Direction::Right){
      step = -1;
    }

    return movable(index += step, cellsToCheck - 1, d);
  }
}

int Block::getBlockLen(){
  return blockLen;
}

void Block::drop(){
  // move down until you can no longer
  while (!autoDrop()){
    down(1);
  }

  // set all block cells in place
  for (Cell * c: blockCells){
    c->setInPlace();
  }
}

Cell * Block::getCell(int row, int col){
  return blockCells[(blockLen*row) + col];
}

void Block::setCell(int row, int col, Cell * newCell){
  delete blockCells[(blockLen*row) + col];
  blockCells[(blockLen*row) + col] = newCell;
}

vector <Cell*>* Block::getBlockCells() {
  return &blockCells;
}

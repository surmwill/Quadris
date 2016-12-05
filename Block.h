#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Cell;

class Block {
 public:
  Block(std::vector <char> blockDesign, int levelGenerated, int blockSize = 4);
  virtual ~Block();
  virtual void left();
  virtual void right();
  virtual void rotate(bool cc);
  virtual void drop();
  virtual void down();
  virtual bool autoDrop();
  virtual Cell * getCell(int row, int col);
  virtual void setCell(int row, int col, Cell * newCell);
  int getBlockLen();

 protected:
  std::vector <Cell*> *getBlockCells();
  std::vector<int> filledIndices;

 private:
  enum class Direction { Left, Right, Down };
  int blockLen;
  std::vector <Cell*> blockCells;
  bool shouldDrop;

  // helper functions
  bool memberCell(int index);
  bool movable(int index, int cellsToCheck, Direction d);
  bool canBeMoved(Direction d);
};

#endif 

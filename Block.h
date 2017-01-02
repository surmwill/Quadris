#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Cell;
class Grid;

class Block {
 public:
  Block(std::vector <char> blockDesign, int levelGenerated, int blockSize = 4);
  virtual ~Block();
  virtual void left(int multi);
  virtual void right(int multi);
  virtual void rotate(bool cc, int multi, Grid * g);
  virtual void drop();
  virtual void down(int multi);
  virtual bool autoDrop();
  virtual Cell * getCell(int row, int col);
  virtual void setCell(int row, int col, Cell * newCell);
  int getBlockLen();
  void printBlockInfo();

 protected:
  std::vector <Cell*> *getBlockCells();
  std::vector<int> filledIndices;

 private:
  enum class Direction { Left, Right, Down };
  int blockLen;
  std::vector <Cell*> blockCells;
  bool shouldDrop = false;

  // helper functions
  bool movable(int index, int cellsToCheck, Direction d);
  bool canBeMoved(Direction d);
};

#endif 

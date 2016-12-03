#ifndef BLOCK_H
#define BLOCK_H 1

#include <vector>

class Cell;

class Block {
 public:
  Block(std::vector <char> blockDesign, int levelGenerated, int blockSize = 4);
  virtual void left();
  virtual void right();
  virtual void rotate(bool cc);
  virtual bool drop():
  virtual bool down();
  virtual bool autoDrop();

 protected:
  std::vector <Cell*> *getBlockCells();
  vector<int> filledIndices;

 private:
  enum class Direction { Left, Right, Down };

  std::vector <Cell*> blockCells;
  bool shouldDrop;
  int blockLen;

  // helper functions
  bool memberCell(int index);
  bool movable(int index, int cellsToCheck, Direction d);
  bool canBeMoved(Direction d)
};

#endif 

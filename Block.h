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
  std::vector <Cell*> blockCells;
  bool autoDrop;

  // helper functions
  bool memberCell(int index);
  bool droppable(int index);
};

#endif 

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
  virtual bool autoDrop();
  virtual bool drop():
  virtual bool down();

 protected:
  std::vector <Cell*> *getBlockCells();
  vector<int> filledIndices;

 private:
  std::vector <Cell*> blockCells;
  bool memberCell(int index);
};

#endif 

#ifndef BLOCK_H
#define BLOCK_H 1

#include <vector>

class Cell;

class Block {
 public:
  Block(std::vector <char> blockDesign, int levelGenerated, int blockSize);
  virtual void left();
  virtual void right();
  virtual void rotatecw();
  virtual void rotatecc();
  virtual bool autoDrop(); 
  virtual bool drop():
  virtual bool down();

 private:
  std::vector <Cell*> blockCells;
};

#endif 

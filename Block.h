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
  static std::vector <Cell*> blockCells; //static variables do not need an instance of a class to intialize
  //we can then delcare what these cells are in the BlockController constructor without actually constructing a block.
  //otherwise we'd have to send 9 grid cells to Level
};

#endif 

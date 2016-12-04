#ifndef BLOCK_CONTROLLER_H
#define BLOCK_CONTROLLER_H

#include <vector>
#include <memory>

class Level;
class Grid;
class Block;
class Cell;

class BlockController {
 public:
   BlockController(Level *level, Grid *grid);
   void left();
   void right();
   void down();
   void rotatecc();
   void rotatecw();
   void drop();
   void genBlock();
   void setBlock(char type); //replaces the current block with block of type char

 private:
   void attachCurrBlockToGrid();
   Grid * grid; //Block Controller is reponsible for deleting grid
   Block * currBlock; //Block Controller is responsible for deleting currBlock
   Block * nextBlock; //Block Controller is responsible for deleing nextBlock
   Level * level;
   std::vector <Cell*> generatingArea;
};

#endif


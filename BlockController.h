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
   BlockController(Level *const level, Grid *grid); 
   void left(int mult);
   void right(int mult);
   void down(int mult);
   void rotatecc(int mult);
   void rotatecw(int mult);
   void drop();
   void genBlock();
   void setBlock(char type);

 private:
   int blockWidth = 4; //the possible width of a block
   int blockHeight = 4; //the possible height of a block
   
   void attachCurrBlockToGrid(); //copies the properties of the block cells to our grid cells
   void nextBlockNotification(); //updates our special cell which notifies the Views with what the next block's design looks like
   Grid * grid; //Block Controller is reponsible for deleting grid
   Level * level; //the current level we are on
   Block * currBlock; //Block Controller is responsible for deleting currBlock
   Block * nextBlock; //Block Controller is responsible for deleing nextBlock
   std::vector <Cell*> generatingArea;
};

#endif

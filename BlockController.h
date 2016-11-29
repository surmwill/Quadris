#include <vector>

#ifndef BLOCK_CONTROLLER_H
#define BLOCK_CONTROLLER_H 1

class Level;
class Grid;
class Block;

class BlockController {
 public:
   BlockController(Level *level, Grid *grid)
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

   std::unique_ptr <Grid> grid; //Block Controller is reponsible for deleting grid
   std::vector <Cell*> generatingArea;
   std::unique_ptr <Block> currBlock; //Block Controller is responsible for deleting currBlock
   std::unique_ptr <Block> nextBlock; //Block Controller is responsible for deleing nextBlock
   Level * level;
};

#ifndef


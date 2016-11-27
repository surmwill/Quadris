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

 private:
   void attachCurrBlockToGrid();

   std::unique_ptr <Grid> grid; //Block Controller is reponsible for deleting grid
   std::unique_ptr <Block> currBlock; //Block Controller is responsible for deleting currBlock
   std::unique_ptr <Block> nextBlock; //Block Controller is responsible for deleing nextBlock
   Level * level;
   std::vector <Cell*> generatingArea;
};

#ifndef


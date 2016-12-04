#ifndef QUADRIS_H
#define QUADRIS_H 1

#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include <string>
#include <memory>

class Quadris {
 public:
   Quadris(int seed, bool textOnly = false, std::string startingSequence = "", int level = 0); //constructs all parts of the program wit the given command line arguments
   void left(); //calls BlockController's left fn
   void right(); //calls BlockController's right fn
   void down(); //calls BlockController's down fn
   void drop(); //calls BlockController's drop fn
   void rotatecc(); //calls BlockController's rotate counter clockwise fn
   void rotatecw(); //calls BlockController's clockwise fn
   void levelup(); //calls LevelController's level up fn
   void leveldown(); //calls LevelController's level down fn
   void setSequence(std::string filename); //calls LevelController's setFilename fn
   void setBlock(char type); //calls BlockController's setBlock fn
   void hint(); //calls HintEngine's hint fn
   void restart(); //calls ViewController's restart fn

 private:
   int level; //the current level
   std::unique_ptr <LevelController> lc; //the level controller
   std::shared_ptr <BlockController> bc; //the block controller
   std::unique_ptr <ViewController> vc; //the view controller
   std::unique_ptr <HintEngine> hintEngine; //the hint engine
};

#endif

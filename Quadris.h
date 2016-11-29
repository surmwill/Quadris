#ifndef QUADRIS_H
#define QUADRIS_H 1

#include "LevelController.h"
#include "BlockController.h"
#include "ViewController.h"
#include "HintEngine.h"
#include <string>

class Quadris {
 public:
   Quadris(int level = 0);
   void left();
   void right();
   void down();
   void rotatecc();
   void rotatecw();
   void levelup();
   void leveldown();
   void setSequence(std::string filename); //previosuly setFileName(string filename);
   void genBlockWithType(char type);
   void hint();
   void restart();

 private:
   int level;
   LevelController lc;
   BlockController bc;
   ViewController vc;
   HintEngine hintEngine;
};

#include "cmdInterpreter.h"
#include <iostream>

#define DEBUG 1

int main(int argc, char *argv[]) {
  //starts the game
  std::istream *in = &std::cin; //can be changed to istream *in = new ifstream(fname.c_str()) where fname is a user inputted string of an input source
  CmdInterpreter cmd{in, argc, argv};

  if(DEBUG == 1) std::cout << "cmdInterpreter constructed" << std::endl;
  cmd.startGame();
}



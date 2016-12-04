#include "CmdInterpreter.h"
#include <iostream>

int main(int argc, char *argv[]) {
  //starts the game
  istream *in == &std::cin; //can be changed to istream *in = new ifstream(fname.c_str()) where fname is a user inputted string of an input source
  CmdInterpreter cmd{in};
  cmd.startGame(argc, argv);
}



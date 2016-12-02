#include "CmdInterpreter.h"
#include <string>
#include <iostream>
#include <locale> //isdigit
#include <cstdlib> //rand
#include <ctime> //time
#include <fstream>

//checks if string s is a valid number
bool isNumber(std::string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
}

//checks if filename can be opened
bool goodFile(std::string filename) {
  if(filename.length() < 1) retrurn false;

  std::ofstream myfile{filename};
  myfile.open()? return true : return false;
}

//parses the command line arguments
void parseArgument(std::string arg1, std::string arg2) {
  if(arg1 == "-text") cmd.textOnly();
  else if(arg1 == "-seed") {
    if(isNumber(arg2) cmd.setSeed(std::stoi(arg2))
    else {
      //randomly give them a seed
      std::cerr << "not given a number for a seed, generating a seed for you" << std::endl;
      std::srand(std::time(0));
      int rand = std::rand() % 100000;
      cmd.setSeed(std::stoi(rand));
    }
  }
  else if(arg1 == "-scriptfile") {
    if(goodFile(arg2)) cmd.setSequence(arg2);
    else std::cerr << "could not read scriptfile" << std::endl;
  }
  else if(arg1 == "-startlevel") {
   if(isNumber(arg2)) cmd.setLevel(std::stoi(arg2));
   else std::cerr << "not given a number for level, starting at level 0" << std::endl;
  }  
}

int main(int argc, char *argv[]) {
  istream *in == &std::cin; //can be changed to istream *in = new ifstream(fname.c_str()) where fname is a user inputted string of an input source
  CmdInterpreter cmd{in};

  //parse the command line arguments
  if(argc > 1) {
    for(int i = 1; i < argv; i++) {
       std::string arg1{argv[i]};
       i < (argv - 1)? std::string arg2{argv[i + 1]} : std::string arg2{""};
       parseArgument(arg1, arg2);
    }
  }

  //starts the game
  cmd.startGame();
}



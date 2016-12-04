#include <string>
#include <iostream>
#include <locale> //needed for isdigit()
#include <cstdlib> //needed for rand()
#include <ctime> //needed for time(0)
#include <fstream>
#include <string>
#include "cmdInterpreter.h"

#define DEBUG 1

using namespace std;

CmdInterpreter::CmdInterpreter(istream * in, int argc, char *argv[]): stream{in}{
  if(argc > 1) {
    for(int i = 1; i < argc; i++) {
      string arg1{argv[i]}; //store the first argument in a string
      string arg2; //the second argument
      (i < (argc - 1)) ? arg2 = argv[i + 1] : arg2 = ""; //if there is no second argument, set the second argument to "" to trigger invalid input
      parseArgument(arg1, arg2); //parse the arguments
    }
  }
  if(DEBUG) cout << "constructing Quadris" << endl;
  quadris = unique_ptr <Quadris> (new Quadris{textOnly, seed, startingSequence, startingLevel});
  if(DEBUG) cout << "CmdInterpreter::CmdInterpreter" << endl;
}

void CmdInterpreter::interpretCommand(string cmd) {
  if (cmd == "left") quadris->left();
  else if (cmd == "right") quadris->right();
  else if (cmd == "down") quadris->down();
  else if (cmd == "clockwise") quadris->rotatecw();
  else if (cmd == "counterclockwise") quadris->rotatecc();
  else if (cmd == "drop") quadris->drop();
  else if (cmd == "levelup") quadris->levelup();
  else if (cmd == "leveldown") quadris->leveldown();
  else if (cmd == "norandom") {
    if(*stream >> cmd)  quadris->setSequence(cmd);
    else cerr << "couldn't read in filename" << endl;
  }
  else if (cmd == "random") quadris->setSequence("");
  else if (cmd == "sequence") { //Note: possible infinite looping if a file "f" calls "sequence f"
    if (*stream >> cmd) {
      ifstream file{cmd, ifstream::in};
      string fileCommand;
      while (file >> fileCommand){ interpretCommand(fileCommand);}
    }
    else cerr <<"couldn't read in filename" << endl;
  } 
  else if (cmd == "restart") quadris->restart();
  else if (cmd == "hint") quadris->hint();
  else if (cmd == "I") quadris->setBlock(cmd[0]);
  else if (cmd == "J") quadris->setBlock(cmd[0]);
  else if (cmd == "L") quadris->setBlock(cmd[0]);
  else if (cmd == "O") quadris->setBlock(cmd[0]);
  else if (cmd == "S") quadris->setBlock(cmd[0]);
  else if (cmd == "Z") quadris->setBlock(cmd[0]);
  else if (cmd == "T") quadris->setBlock(cmd[0]);
  else cerr << "unrecognized command" << endl;
}

void CmdInterpreter::startGame(){
  string cmd;
  while (*stream >> cmd){
    interpretCommand(cmd);
  }
}

void CmdInterpreter::parseArgument(std::string arg1, std::string arg2) {
  if(arg1 == "-text") textOnly = true;
  else if(arg1 == "-seed") {
    if(isNumber(arg2)) seed = stoi(arg2); //check that we have a valid second argument
    else {
      //otherwise randomly give them a seed
      cerr << "not given a number for a seed, generating a seed for you" << endl;
      srand(time(0));
      seed = rand() % 100000;
    }
  }
  else if(arg1 == "-scriptfile") {
    if(goodFile(arg2)) startingSequence = arg2; //check that we have a valid second argument
    else cerr << "could not read scriptfile" << endl;
  }
  else if(arg1 == "-startlevel") {
    if(isNumber(arg2)) startingLevel = std::stoi(arg2); //check that we have a valid second argument
    else cerr << "not given a number for level, starting at level 0" << endl;
  }
}

bool CmdInterpreter::goodFile(std::string filename) {
  if(filename.length() < 1) return false;

  ofstream myfile{filename};
  if(myfile.is_open()) return true;
  else return false;
}

bool CmdInterpreter::isNumber(std::string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
}

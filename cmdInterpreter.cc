#include <string>
#include <iostream>
#include <locale> //needed for isdigit()
#include <cstdlib> //needed for rand()
#include <string>
#include <fstream>
#include "cmdInterpreter.h"

#define DEBUG 1

using namespace std;

CmdInterpreter::CmdInterpreter(istream * in, int argc, char *argv[]): stream{in}, textOnly{false}, newSeed{false}, seed{0}, startingLevel{0} {
  if(argc > 1) {
    for(int i = 1; i < argc; i++) {
      string arg1{argv[i]}; //store the first argument in a string
      string arg2; //the second argument
      (i < (argc - 1)) ? arg2 = argv[i + 1] : arg2 = ""; //if there is no second argument, set the second argument to "" to trigger invalid input
      parseArgument(arg1, arg2); //parse the arguments
    }
  }
  if(DEBUG) cout << "text only? " << textOnly << endl;
  if(DEBUG) cout << "constructing Quadris" << endl;
  quadris = unique_ptr <Quadris> (new Quadris{seed, newSeed, textOnly, startingSequence, startingLevel});
  if(DEBUG) cout << "CmdInterpreter::CmdInterpreter" << endl;
}

void CmdInterpreter::interpretCommand(string cmd) {
  int mult = extractInt(&cmd);

  if (cmd == "left") quadris->left(mult);
  else if (cmd == "right") quadris->right(mult);
  else if (cmd == "down") quadris->down(mult);
  else if (cmd == "clockwise") quadris->rotatecw(mult);
  else if (cmd == "counterclockwise") quadris->rotatecc(mult);
  else if (cmd == "drop") quadris->drop(mult);
  else if (cmd == "levelup") quadris->levelup(mult);
  else if (cmd == "leveldown") quadris->leveldown(mult);
  else if (cmd == "norandom") {
    if(*stream >> cmd) quadris->setSequence(cmd);
    else cerr << "couldn't read in filename" << endl;
  }
  else if (cmd == "random") quadris->setSequence("");
  else if (cmd == "sequence") { //Note: possible infinite looping if a file "f" calls "sequence f"
    if(*stream >> cmd) { 
      for(int i = 0; i < mult; i++) {
        ifstream file{cmd, ifstream::in};
        string fileCommand;
        while (file >> fileCommand){ interpretCommand(fileCommand);}
      }
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

void CmdInterpreter::parseArgument(const string arg1, const string arg2) {
  if(arg1 == "-text") {
    if(DEBUG) cout << "text only" << endl;
    textOnly = true;
  }
  else if(arg1 == "-seed") {
    if(isNumber(arg2)) { //check that we have a valid second argument
       srand(stoi(arg2)); 
       newSeed = true;
    }
  }
  else if(arg1 == "-scriptfile") startingSequence = arg2; 
  else if(arg1 == "-startlevel") {
    if(isNumber(arg2)) { //check that we have a valid second argument
      startingLevel = std::stoi(arg2); 
      if(startingLevel < 0) startingLevel = 0;
      if(startingLevel > 4) startingLevel = 4;
    }
    else cerr << "not given a number for level, starting at level 0" << endl;
  }
}

int CmdInterpreter::extractInt(string * s) {
  string toConvert;
  int deleted = 0;

  for(auto &n: *s) {
    if(!isdigit(n)) break;
    toConvert += n;
    deleted++;
  }
  *s = s->substr(deleted);
  
  if(toConvert.length() == 0) return 0;
  else return stoi(toConvert);
}

bool CmdInterpreter::isNumber(const string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
}

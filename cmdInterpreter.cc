#include <string>
#include <iostream>
#include <locale> //needed for isdigit()
#include <cstdlib> //needed for rand()
#include <fstream>
#include <string>
#include "cmdInterpreter.h"

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
  quadris = unique_ptr <Quadris> (new Quadris{seed, newSeed, textOnly, startingSequence, startingLevel});

  //creates of vector of all known commands to the program (maybe change to text file)
  commands.emplace_back("left");
  commands.emplace_back("right");
  commands.emplace_back("down");
  commands.emplace_back("clockwise");
  commands.emplace_back("counterclockwise");
  commands.emplace_back("drop");
  commands.emplace_back("levelup");
  commands.emplace_back("leveldown");
  commands.emplace_back("norandom");
  commands.emplace_back("random");
  commands.emplace_back("sequence");
  commands.emplace_back("restart");
  commands.emplace_back("hint");
  commands.emplace_back("I");
  commands.emplace_back("J");
  commands.emplace_back("L");
  commands.emplace_back("O");
  commands.emplace_back("S");
  commands.emplace_back("Z");
  commands.emplace_back("T");
} 

void CmdInterpreter::interpretCommand(string cmd) {
  int multi = determineMultiplicity(&cmd);
  cmd = completeCommand(cmd);

  if (cmd == "left") quadris->left(multi);
  else if (cmd == "right") quadris->right(multi);
  else if (cmd == "down") quadris->down(multi);
  else if (cmd == "clockwise") quadris->rotatecw(multi);
  else if (cmd == "counterclockwise") quadris->rotatecc(multi);
  else if (cmd == "drop") quadris->drop(multi);
  else if (cmd == "levelup") quadris->levelup(multi);
  else if (cmd == "leveldown") quadris->leveldown(multi);
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

string CmdInterpreter::completeCommand(string userCommand) {
  string finalCommand = "";
  
  for(auto &m: commands) {
     if(userCommand.length() > m.length()) continue;
     size_t found = m.find(userCommand);

     if(found == 0 && (finalCommand.length() == 0 || m.length() < finalCommand.length())) finalCommand = m;
  }

  return finalCommand;
}

int CmdInterpreter::determineMultiplicity(std::string * userCommand) {
  int multi = 1;
  string stringMulti = "";

  for(auto &n: *userCommand) {
    if(!isdigit(n)) break;
    stringMulti += n;
  }

  if(stringMulti.length() > 0) {
    multi = stoi(stringMulti);

    int stringCut = stringMulti.length();
    *userCommand = (*userCommand).substr(stringCut);
  }

  return multi;
}

void CmdInterpreter::parseArgument(std::string arg1, std::string arg2) {
  if(arg1 == "-text") {
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

bool CmdInterpreter::isNumber(std::string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
}

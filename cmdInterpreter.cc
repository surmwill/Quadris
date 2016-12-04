#include <string>
#include <iostream>
#include <locale> //needed for isdigit()
#include <cstdlib> //needed for rand()
#include <ctime> //needed for time(0)
#include "cmdInterpreter.h"

using namespace std;

CmdInterpreter::CmdInterpreter(istream * in, int argc, char *argv[]): stream{in}{
  if(argc > 1) {
    for(int i = 1; i < argc; i++) {
      string arg1{argv[i]}; //store the first argument in a string
      i < (argv - 1)? std::string arg2{argv[i + 1]} : std::string arg2{""}; //if there is no second argument, set the second argument to "" to trigger invalid input
      parseArgument(arg1, arg2); //parse the arguments
    }
  }
}

void CmdInterpreter::interpretCommand(string cmd){
  if (cmd == "left"){
    mController.left();
  } else if (cmd == "right") {
    mController.right();
  } else if (cmd == "down"){
    mController.down();
  } else if (cmd == "clockwise"){
    mController.rotatecw();
  } else if (cmd == "counterclockwise"){
    mController.rotetecc();
  } else if (cmd == "drop"){
    mController.drop();
  } else if (cmd == "levelup"){
    mController.levelUp();
  } else if (cmd == "leveldown"){
    mController.levelDown();
  } else if (cmd == "norandom"){
    if (stream >> cmd){
      mController.setSequence(cmd);
    } else {
      // Failed to read in filename. Throw an error.
    }
  } else if (cmd == "random"){
    mController.setSequence("");
  } else if (cmd == "sequence"){
    //This can allow for infinite looping if a file "f" calls "sequence f"
    if (*stream >> cmd){
      ifstream file(cmd);
      // maybe reuse cmd instead of making string fileCommand
      string fileCommand;
      // maybe change stream to file, call startGame(), then change stream back
      while (file >> fileCommand){
        interpretCommand(fileCommand);
      }
    } else {
      // Failed to read in filename. Throw an error.
    }
  } else if (cmd == "restart"){
    mController.restart();
  } else if (cmd = "hint"){
    mController.hint();
  } else if (cmd == "I"){
    // Maybe add all subsequent block drops into one if statement
  } else if (cmd == "J"){
    // Maybe allow for block fills to be greater than one char in length
  } else if (cmd == "L"){
    // Maybe have mController.dropBlockWithType return bool,
    // true if such a block exists, false otherwise.
  } else if (cmd == "O"){
    // If dropBlockWithType returns false, then execute else code
  } else if (cmd == "S"){
    //
  } else if (cmd == "Z"){
    //
  } else if (cmd == "T"){
    //
  } else {
    // not a recognized command. Throw an error.
  }
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
    if(isNumber(arg2)) seed = std::stoi(arg2) //check that we have a valid second argument
    else {
      //otherwise randomly give them a seed
      std::cerr << "not given a number for a seed, generating a seed for you" << std::endl;
      std::srand(std::time(0));
      int rand = std::rand() % 100000;
      seed = std::stoi(rand);
    }
  }
  else if(arg1 == "-scriptfile") {
    if(goodFile(arg2)) startingSequence = arg2; //check that we have a valid second argument
    else std::cerr << "could not read scriptfile" << std::endl;
  }
  else if(arg1 == "-startlevel") {
    if(isNumber(arg2)) startingLevel = std::stoi(arg2); //check that we have a valid second argument
    else std::cerr << "not given a number for level, starting at level 0" << std::endl;
  }
}

bool CmdInterpreter::goodFile(std::string filename) {
  if(filename.length() < 1) return false;

  std::ofstream myfile{filename};
  myfile.open()? return true : return false;
}

bool CmdInterpreter::isNumber(std::string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
}

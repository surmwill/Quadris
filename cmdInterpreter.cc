#include <string>
#include "cmdInterpreter.h"

class CmdInterpreter {
  Quatris mController;
  istream stream;
  public:

CmdInterpreter::CmdInterpreter(istream * in): stream{in}{}


void interpretCommand(string cmd){
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
      mController.setFileName(cmd);
    } else {
      // Failed to read in filename. Throw an error.
    }
  } else if (cmd == "random"){
    mController.setFileName("");
  } else if (cmd == "sequence"){
    //This can allow for infinite looping if a file "f" calls "sequence f"
    if (stream >> cmd){
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

void startGame(){
  string cmd;
  while (stream >> cmd){
    interpretCommand(cmd);
  }
}






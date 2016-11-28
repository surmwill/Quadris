#include <string>
#include "quatris.h"

class CmdInterpreter {
  Quatris mController;
  istream stream;

  void interpretCommand(std::string cmd);
  
  public:
    CmdInterpreter(std::istream * in);
    void startGame();
}


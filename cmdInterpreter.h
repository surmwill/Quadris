#include <string>
#include "Quadris.h"

class CmdInterpreter {
  private:
    Quadris mController; //Calls different parts of the program
    istream *stream; //The input stream

    void interpretCommand(std::string cmd); //Determines what part of the program to call with a given command
    void parseArguments(std::string arg1, std::string arg2); //Parses command line arguments
    bool goodFile(std::string s); //checks if a file with name s can be opened
    bool isNumber(std::string s); //checks if string s is a valid number

  public:
    CmdInterpreter(std::istream * in); //Triggers the cosntruction, of the rest of the program, sets the input stream, parses command line arguments
    void startGame(); //Begins the input and evaluation of commands
}


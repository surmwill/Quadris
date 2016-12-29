#include <string>
#include "Quadris.h"
#include <memory>
#include <vector>

class CmdInterpreter {
  private:
    typedef void (*voidCommand) (void);
    typedef void (*charCommand) (char);
    std::unique_ptr <Quadris> quadris; //Calls different parts of the program
    std::istream *stream; //The input stream
    std::vector <std::string> commands;
   

    //These 4 values store command line arguments to pass to the Quadris constructor
    bool textOnly; //Text only mode
    bool newSeed; //If the user enetered a new seed
    int seed; //Seed for random number generation
    std::string startingSequence; //Intial file to read input from
    int startingLevel; //The starting level
    

    void interpretCommand(std::string cmd); //Determines what part of the program to call with a given command
    void parseArgument(std::string arg1, std::string arg2); //Parses command line arguments
    bool isNumber(std::string s); //checks if string s is a valid number
    std::string completeCommand(std::string userCommand); //auto completes the users command if possible (ri -> right)
    int determineMultiplicity(std::string *userCommand); //determines how many times the user wishes the command to repeat, removes these multiplicity numbers from the string

  public:
    CmdInterpreter(std::istream * in, int argc, char *argv[]); //Triggers the cosntruction, of the rest of the program, sets the input stream, parses command line arguments
    void startGame(); //Begins the input and evaluation of commands
};

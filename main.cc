#include "CmdInterpreter.h"
#include <string>
#include <iostream>
#include <locale>

void parseArgument(std::string arg1, std::string arg2) {
  if(arg == "-text") cmdInterpreter.textOnly();
  else if(arg == "-seed") {
    (arg2 != "")? cmdInterpreter.setSeed(std::stoi
}

void checkIfNumber(std::string s) {
  for(auto &n: s) {
    if(!isdigit(
}

int main(int argc, char *argv[]) {
  if(argc > 1) {
    for(int i = 1; i < argv; i++) {
       std::string arg1{argv[i]};
       i < (argv - 1)? std::string arg2{argv[i + 1]} : std::string arg2{""};
       parseArgument(arg1, arg2);
    }
  }
}



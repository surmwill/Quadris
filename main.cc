#include "CmdInterpreter.h"
#include <string>
#include <iostream>
#include <locale> //isdigit
#include <cstdlib> //rand

void parseArgument(std::string arg1, std::string arg2) {
  if(arg1 == "-text") cmdInterpreter.textOnly();
  else if(arg1 == "-seed") {
    if(isNumber(arg2) cmdInterpreter.setSeed(std::stoi(arg2))
    else  cmdInterpreter.setSeed(100);
        
}

bool isNumber(std::string s) {
  if(s.length() < 1) return false;

  for(auto &n: s) {
    if(!isdigit(n)) return false;
  }
  return true;
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



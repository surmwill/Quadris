#ifndef LEVEL_H
#define LEVEL_H 1

#include <string>
#include <vector>

class Level{
  private:
    std::string fileName;
    int levelNum;

  protected:
    void setFilename(std::string fileName);
    Level();

  public:
    virtual std::vector<char> genBlock() = 0;
    virtual std::vector<char> genBlock() = 0;
    ~Level() = 0;
};

#endif

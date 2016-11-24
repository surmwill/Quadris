#include <string>
#include <vector>

class Level{
  std::string filename;
  int levelNum;
  
  protected:
    std::string getFilename();
  
  public:
    virtual std::vector<char> genBlock();
    virtual std::vector<char> genBlock(std::char);
    void setFileName();
    int getLevel();
}

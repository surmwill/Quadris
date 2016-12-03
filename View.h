#ifndef VIEW_H
#define VIEW_H 1

#include "Observer.h"
#include "BlockLib.h"
#include <vector>

class SubscriptionType;
class Subject;

class View: public Observer {
 public:
  virtual void notify(const Subject &whoNotified) = 0; //when a Cell changes state the View is notified and passed the Cell
  virtual void display(const Score &score) = 0; //the ViewController will call this when the score is updated or the grid needs redrawing
  virtual void showHint(const std::vector <std::vector <int>> & coords) = 0; //draws the hint location by colouring in Cells with the given coordinates
  virtual void clear() = 0;  //clears the View's grid, but not the hi score
  void setLevel(const int level) = 0; //sets the level that the View is displaying
  SubscriptionType subTye(); //the Views subscription type (View)
  virtual ~View() = 0;

 protected:
  int getLevel(); //returns the level we are on
  BlockLib & getBlockLib(); //returns the block library used to draw the design of next block
  View(const int startLevel = 0); //intializes the board to blank

 private:
  int level;
  BlockLib blockLib;
};

#endif

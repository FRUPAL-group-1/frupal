#include <iostream>
#include <curses.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class NcursesController
{
  public:
    NcursesController();
    ~NcursesController();

    void initializeColor();
    void displayFrame(char map[128][128], int herox, int heroy);

  private:
    //define names to the colorpair settings
    int MEADOW_PAIR;
    int SWAMP_PAIR;
    int WATER_PAIR;
    int WALL_PAIR;
    int HERO_PAIR;
    int DIAMOND_PAIR;

};

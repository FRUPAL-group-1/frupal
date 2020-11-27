#include <iostream>
#include <curses.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "character.h"

using namespace std;

class NcursesController
{
  public:
    NcursesController();
    ~NcursesController();

    void initializeColor();
    void discover(int herox, int heroy, int discovered[128][128], bool binocular);
    void displayFrame(char map[128][128], int herox, int heroy, int discovered[128][128], bool binocular);
    void move_hero(char map[128][128], int discovered[128][128], Character &hero, int keypress);
    int checkMove(int xaxis, int yaxis, char map[128][128], bool boat, Character &hero);
    void displayMove(int whiffles, int energy);

  private:
    //define names to the colorpair settings
    int MEADOW_PAIR;
    int SWAMP_PAIR;
    int WATER_PAIR;
    int WALL_PAIR;
    int HERO_PAIR;
    int DIAMOND_PAIR;

};

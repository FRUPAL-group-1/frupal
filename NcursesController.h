#ifndef NCURSES
#define NCURSES

#include <iostream>
#include <curses.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "character.h"
#include "map.h"

using namespace std;

class NcursesController
{
  public:
    NcursesController();
    ~NcursesController();

    void initializeColor();
    void discover(int herox, int heroy, int discovered[128][128], bool binocular);
    void displayFrame(char map[128][128], int herox, int heroy, int discovered[128][128], bool binocular, Grovnick * grovnicks[128][128]);
    void move_hero(char map[128][128], int discovered[128][128], Character &hero, int keypress, Grovnick * grovnicks[128][128]);
    int checkMove(int xaxis, int yaxis, char map[128][128], bool boat, Character &hero);
    void displayMove(int whiffles, int energy);
    void move_cursor(char map[128][128], int discovered[128][128], int keypress, int& herocursorx, int& herocursory);
    int checkCursorMove(int cursor_x, int cursor_y, int herocursory, int herocursorx, int discovered[128][128]);
    bool displaygrovnick(int y, int x, int printy, int printx, Grovnick * grovnicks[128][128]);

  private:
    //define names to the colorpair settings
    int MEADOW_PAIR;
    int SWAMP_PAIR;
    int WATER_PAIR;
    int WALL_PAIR;
    int HERO_PAIR;
    int DIAMOND_PAIR;

};

#endif  //NCURSES

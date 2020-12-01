#ifndef NCURSES_CPP
#define NCURSES_CPP

//NcursesController class
//handles the display of the frupal game
//Displays map, character stats and options

#include "NcursesController.h"

//default constructor
NcursesController::NcursesController()
{
  MEADOW_PAIR = 1;
  SWAMP_PAIR = 2;
  WATER_PAIR = 3;
  WALL_PAIR = 4;
  HERO_PAIR = 5;
  DIAMOND_PAIR = 6;
}

//destructor
NcursesController::~NcursesController()
{

}

void NcursesController::discover(int herox, int heroy, int discovered[128][128], bool binocular)
{
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  herox++;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  heroy++;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  herox--;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  herox--;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  heroy--;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  heroy--;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  herox++;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  herox++;
  if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
    discovered[heroy][herox] = 1;
  }
  if(binocular) {
    herox++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    heroy--;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
    herox++;
    if(herox <= 127 && herox >= 0 && heroy <= 127 && heroy >= 0){
      discovered[heroy][herox] = 1;
    }
  }
}

int NcursesController::checkMove(int xaxis, int yaxis, char map[128][128], bool boat, Character &hero)
{
  int good = 1;
  if(xaxis < 0 || xaxis > 127 || yaxis < 0 || yaxis > 127)
    return 0;
  switch(map[yaxis][xaxis])
  {
    case 'm':
      break;
    case 's':
      hero.spendEnergy(1);
      break;
    case 'w':
      good = 0;
      hero.spendEnergy(1);
      break;
    case 'b':
      if(boat)
        break;
      good = 0;
      break;
  }
  return good;
}


void NcursesController::initializeColor() //set up the color pairs for the program (foreground and background)
{
  start_color();
  init_pair(MEADOW_PAIR, COLOR_BLACK, COLOR_GREEN);
  init_pair(SWAMP_PAIR, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(WATER_PAIR, COLOR_BLACK, COLOR_BLUE);
  init_pair(WALL_PAIR, COLOR_BLACK, COLOR_WHITE);
  init_pair(HERO_PAIR, COLOR_YELLOW, COLOR_RED);
  init_pair(DIAMOND_PAIR, COLOR_WHITE, COLOR_CYAN);
}


//displays the current map frame, with the hero centered
void NcursesController::displayFrame(char map[128][128], int herox, int heroy, int discovered[128][128], bool binocular)
{
  erase(); //clear screen to prevent out of bounds
  discover(herox,heroy,discovered,binocular);
  int viewport_width = COLS - 30; //width of displayport, minus space to display options/info
  int viewport_height = LINES; //height of the window
  int hero_xspot = floor(viewport_width/2); //center of displayport x axis
  int hero_yspot = floor(viewport_height/2); //center of displayport y axis

  //handles edge screen buffer for even and odd window sizes
  int y_adder = 2;
  int ycheck = viewport_height;
  if(ycheck % 2 == 0)
    y_adder--;

  int x_adder = 3;
  int xcheck = viewport_width;
  if(xcheck % 2 == 0)
    x_adder--;

  //vertical line to separate viewport from menu
  mvvline(0, viewport_width+1, '#', viewport_height);

  //loop through map array and display info on screen
  for(int y = (heroy - (hero_yspot-1)), printy = 0; y < (heroy + hero_yspot + y_adder); y++) {
    if(y < 0 || y > 127) {
      printy++;
      continue;
    }
    for(int x = (herox - (hero_xspot-1)), printx = 0; x < (herox + hero_xspot + x_adder); x++) {
      if(x < 0 || x > 127) {
        printx++;
        continue;
      }
      switch(map[y][x]) {
        case 'm':
          if(discovered[y][x]){
            attron(COLOR_PAIR(MEADOW_PAIR));
            mvaddch(printy,printx,' ');
            attroff(COLOR_PAIR(MEADOW_PAIR));
          }
          break;
        case 'w':
          if(discovered[y][x]){
            attron(COLOR_PAIR(WALL_PAIR));
            mvaddch(printy,printx,' ');
            attroff(COLOR_PAIR(WALL_PAIR));
          }
          break;
        case 's':
          if(discovered[y][x]){
            attron(COLOR_PAIR(SWAMP_PAIR));
            mvaddch(printy,printx,' ');
            attroff(COLOR_PAIR(SWAMP_PAIR));
          }
          break;
        case 'b':
          if(discovered[y][x]){
            attron(COLOR_PAIR(WATER_PAIR));
            mvaddch(printy,printx,' ');
            attroff(COLOR_PAIR(WATER_PAIR));
          }
          break;
      }
      printx++;
    }
    printy++;
  }
  //print hero
  attron(COLOR_PAIR(HERO_PAIR));
  mvaddch(hero_yspot-1,hero_xspot-1,'@');
  attroff(COLOR_PAIR(HERO_PAIR));
  refresh();
}

void NcursesController::displayMove(int whiffles, int energy)
{
  int leftbuffer = COLS - 28;
  mvprintw(6, leftbuffer, "Options:");
  mvprintw(7, leftbuffer, "W: Move North");
  mvprintw(8, leftbuffer, "A: Move West");
  mvprintw(9, leftbuffer, "S: Move South");
  mvprintw(10, leftbuffer, "D: Move East");



  mvprintw(LINES-1, leftbuffer, "Energy: %d", energy);
  mvprintw(LINES-2, leftbuffer, "Whiffles: %d", whiffles);
}

void NcursesController::move_hero(char map[128][128], int discovered[128][128], Character &hero, int keypress)
{
  curs_set(0);
  initializeColor();

  int yaxis = hero.yAxis;
  int xaxis = hero.xAxis;

  displayMove(hero.whiffles,hero.energy);
  switch(keypress) {
    case 1:
      if(checkMove(xaxis-1, yaxis, map, hero.hasBoat(), hero))
      {
        xaxis--;
        displayFrame(map, xaxis, yaxis, discovered, hero.hasBinoculars());
        hero.spendEnergy(1);
        displayMove(hero.whiffles,hero.energy);
      }
      break;

    case 2:
      if(checkMove(xaxis, yaxis+1, map, hero.hasBoat(), hero))
      {
        yaxis++;
        displayFrame(map, xaxis, yaxis, discovered, hero.hasBinoculars());
        hero.spendEnergy(1);
        displayMove(hero.whiffles,hero.energy);
      }
      break;

    case 3:
      if(checkMove(xaxis, yaxis-1, map, hero.hasBoat(), hero))
      {
        yaxis--;
        displayFrame(map, xaxis, yaxis, discovered, hero.hasBinoculars());
        hero.spendEnergy(1);
        displayMove(hero.whiffles,hero.energy);
      }
      break;

    case 4:
      if(checkMove(xaxis+1, yaxis, map, hero.hasBoat(), hero))
      {
        xaxis++;
        displayFrame(map, xaxis, yaxis, discovered, hero.hasBinoculars());
        hero.spendEnergy(1);
        displayMove(hero.whiffles,hero.energy);
      }
      break;

    default:
      break;
  }
  hero.yAxis = yaxis;
  hero.xAxis = xaxis;
  mvprintw(16, COLS-28, "hero y: %d  Hero x: %d", hero.yAxis, hero.xAxis);

  // set cursor to hero
  move((LINES/2)-1, ((COLS-30)/2)-1);
}


// This function checks to make sure the cursor is not out-of-bounds
int NcursesController::checkCursorMove(int cursor_x, int cursor_y, int herocursory, int herocursorx, int discovered[128][128])
{
  int good = 1;

  if(cursor_x < 0 || cursor_x > COLS-30 || cursor_y < 0 || cursor_y > LINES-1) //checks screen bounds
  {
    mvprintw(20, COLS-28, "test fail");
    return 0;
  }
  if(herocursorx < 0 || herocursorx > 127 || herocursory < 0 || herocursory > 127) //checks map bounds
  {
    mvprintw(20, COLS-28, "test fail");
    return 0;
  }
  if(!(discovered[herocursory][herocursorx]))
  {
    mvprintw(20, COLS-28, "test fail");
    return 0;
  }

  mvprintw(20, COLS-28, "passed test");
  return good;
}


// This function moves the cursor, not the hero
void NcursesController::move_cursor(char map[128][128], int discovered[128][128], int keypress, int& herocursorx, int& herocursory)
{
  curs_set(1);

  int cursor_y, cursor_x;
  getyx(stdscr, cursor_y, cursor_x);

  switch(keypress) {

    case 1:
      if(checkCursorMove(cursor_x, cursor_y-1, herocursory-1, herocursorx, discovered))
      {
        cursor_y--;
        herocursory--;
      }

      break;

    case 2:
      if(checkCursorMove(cursor_x, cursor_y+1, herocursory+1, herocursorx, discovered))
      {
        cursor_y++;
        herocursory++;
      }

      break;

    case 3:
      if(checkCursorMove(cursor_x-1, cursor_y, herocursory, herocursorx-1, discovered))
      {
        cursor_x--;
        herocursorx--;
      }

      break;

    case 4:
      if(checkCursorMove(cursor_x+1, cursor_y, herocursory, herocursorx+1, discovered))
      {
        cursor_x++;
        herocursorx++;
      }

      break;

    default:
      break;
  }

  mvprintw(18, COLS-28, "cursor y: %d  cursor x: %d", herocursory, herocursorx);
  wmove(stdscr, cursor_y, cursor_x);
  refresh();
}

#endif  //NCURSES_CPP

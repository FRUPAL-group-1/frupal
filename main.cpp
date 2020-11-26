#include "gameController.h"
using namespace std;

int main()
{
  initscr();
  noecho();
  keypad(stdscr, true);

  GameController game;
  game.loadMap();
  game.update();

  endwin();
  return 0;
}

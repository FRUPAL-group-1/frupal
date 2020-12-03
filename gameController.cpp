#ifndef GAMECONT_CPP
#define GAMECONT_CPP

//impliments all of the gameController functions

#include "gameController.h"


GameController::GameController()
{
}
GameController::~GameController()
{
}


bool GameController::update()
{
  int keypress = 5;  //declare once
  int cursorx; //keep track of cursor when hero moves
  int cursory; //keep track of cursor when hero moves
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
  cursorx = hero.xAxis; //give starting hero xvalue
  cursory = hero.yAxis; //give starting hero yvalue

  while(keypress != 0){
    keypress = getch();
    switch(keypress)
    {
      //case 1
      case 'a':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //case 2
      case 's':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 2);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //case 3
      case 'w':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 3);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //case 4
      case 'd':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //quit
      case 'q':
        return 0;
        break;

        //cursor up
      case KEY_UP:
        ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 1, cursorx, cursory);
        break;

        //cursor down
      case KEY_DOWN:
        ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 2, cursorx, cursory);
        break;

        //cursor left
      case KEY_LEFT:
        ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 3, cursorx, cursory);
        break;

        //cursor right
      case KEY_RIGHT:
        ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 4, cursorx, cursory);
        break;

      default:
        break;
    }
    if(hero.energy <= 0) //end game at 0 energy
    {
      return 0;
    }

  }
  return 0;
}


bool GameController::loadMap()
{
  currentMap.initializeMap();
  currentMap.initializeGrovnicks();
  return true;
}

#endif  //GAMECONT_CPP


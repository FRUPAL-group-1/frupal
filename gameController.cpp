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
  ncursescontroller.displayFrame(currentMap.map, hero.xAxis, hero.yAxis, currentMap.discovered, false);
  while(keypress != 0){
    keypress = getch();
    switch(keypress)
    {
      //case 1
      case 'a':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
        break;

        //case 2
      case 's':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 2);
        break;

        //case 3
      case 'w':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 3);
        break;

        //case 4
      case 'd':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
        break;

        //quit
      case 'q':
        return 0;
        break;

      default:
        break;
    }

  }
  return 0;
}


bool GameController::loadMap()
{
  currentMap.initializeMap();
  return true;
}

#endif  //GAMECONT_CPP


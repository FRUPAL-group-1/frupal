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
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
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

	//cursor up
      case KEY_UP:
	ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 1, hero);
	break;

	//cursor down
      case KEY_DOWN:
	ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 2, hero);
	break;

	//cursor left
      case KEY_LEFT:
	ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 3, hero);
	break;

	//cursor right
      case KEY_RIGHT:
	ncursescontroller.move_cursor(currentMap.map, currentMap.discovered, 4, hero);
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
  return true;
}

#endif  //GAMECONT_CPP


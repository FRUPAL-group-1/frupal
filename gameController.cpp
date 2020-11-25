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
  initscr();
  char ch;  //declare once
  ch = getInput(ch);
  do
  {
    switch(ch)
    {
      //case 2
      case 'N':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero);
        getInput();
        break;
        
      //case 4
      case 'E':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
        getInput();
        break;

      //case 3
      case 'S':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 3);
        getInput();
        break;

      //case 1
      case 'W':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
        getInput();
        break;

      //quit
      case 'Q':
        return 0;
        break;

      default:
        break;
    }

  }while((ch) != 'Q');
  return 0;
}


//helper function to keep loop clean
char GameController::getInput(char ch)
{
  cin >> ch;
  return toupper(ch);
}

#endif  //GAMECONT_CPP

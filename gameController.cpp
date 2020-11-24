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
  char ch;  //declare once
  ch = getInput(ch)
  do
  {
    switch(ch)
    {
      //case 2
      case 'N':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 2);
        getinput();
        break;
        
      //case 4
      case 'E':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4);
        getinput();
        break;

      //case 3
      case 'S':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 3);
        getinput();
        break;

      //case 1
      case 'W':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1);
        getinput();
        break;

      //quit
      case 'Q':
        return 0;
        break;

      default:
        break;
    }

  }while((ch) != 'Q');
}


//helper function to keep loop clean
char gameController::getInput(ch)
{
  cin >> ch;
  return toupper(ch);
}

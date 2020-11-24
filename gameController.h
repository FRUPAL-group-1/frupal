//gameController class
//Handles the overall game:
//provides game name
//the map
//the character
//loads in the csv mapdata

#include "NcursesController.h"
#include "character.h"
#include "locations.h"
#include "map.h"
#include <iostream> //may be defined in a global file

using namespace std;

class GameController
{
  public:
    Locations locations;
    Character hero;
    NcursesController ncursescontroller;
    Map currentMap;

    GameController();
    ~GameController();

    bool loadMap();
    bool update();
    char getInput(char ch);
};

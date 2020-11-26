//gameController class
//Handles the overall game:
//provides game name
//the map
//the character
//loads in the csv mapdata

#include "NcursesController.h"
#include "map.h"

using namespace std;

class GameController
{
  public:
    Character hero;
    NcursesController ncursescontroller;
    Map currentMap;

    GameController();
    ~GameController();

    bool loadMap();
    bool update();
};

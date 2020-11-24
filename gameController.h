//gameController class
//Handles the overall game:
//provides game name
//the map
//the character
//loads in the csv mapdata

#include "NcursesController.h"
#include "charachter.h"
#include "locations.h"
#include "map.h"

using namespace std;

class GameController
{
  public:
    Locations locations;
    Map maps;
    Character hero;
    NcursesController ncursescontroller;

    GameController();
    ~GameController();

    bool update();
  private:
};

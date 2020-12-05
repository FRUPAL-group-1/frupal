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
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4, currentMap.grovnicks);
  ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1, currentMap.grovnicks);
  cursorx = hero.xAxis; //give starting hero xvalue
  cursory = hero.yAxis; //give starting hero yvalue

  while(keypress != 0){
    keypress = getch();
    switch(keypress)
    {
      //case 1
      case 'a':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 1, currentMap.grovnicks);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;



        break;

        //case 2
      case 's':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 2, currentMap.grovnicks);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //case 3
      case 'w':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 3, currentMap.grovnicks);
        cursorx = hero.xAxis;
        cursory = hero.yAxis;
        break;

        //case 4
      case 'd':
        ncursescontroller.move_hero(currentMap.map, currentMap.discovered, hero, 4, currentMap.grovnicks);
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

    //if true, then its a tool
    if( (currentMap.grovnicks[hero.yAxis][hero.xAxis])->type == 3 )
    {
      Grovnick *current = currentMap.grovnicks[hero.yAxis][hero.xAxis];
      
      //here the Tool class also calls the constructor for the Grovnick base class, and it should work, but doesnt!
      Grovnick *toolptr = new Tool( current->y_axis, 
                                    current->x_axis,
                                    current->cost, 
                                    current->type,
                                    current->name,
                                    current->tool_type,           //in the Tool derived class
                                    current->item_effectiveness   //in the Tool derived class
                                   );
      hero.addToolToInventory(toolptr);
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

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
  int leftbuffer = COLS - 28;
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

      case 'x': //interact with object hero is over
        if(currentMap.grovnicks[hero.yAxis][hero.xAxis])
        {
          Grovnick * current = currentMap.grovnicks[hero.yAxis][hero.xAxis];

          switch(current->type){
            case 1: //food
              {
                if(hero.whiffles >= current->cost)
                {
                  Food * food = dynamic_cast<Food *>(current);
                  hero.addEnergy(food->restore);
                  hero.spendWhiffles(food->cost);
                  currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;
                  ncursescontroller.displayMove(hero.whiffles, hero.energy);
                  move((LINES/2)-1, ((COLS-30)/2)-1);
                }
                break;
              }
            case 2:
              {
                char ch;
                //I DO THIS INSIDE THE FUNCTION
                //Obstacle *currentObstacle = dynamic_cast<Obstacle *>(current);
                mvprintw(LINES-10, leftbuffer, " What tool to use?");
                //mvprintw( 30, leftbuffer, "Hello");
                hero.printTools();
                ch = getch();
                switch(ch)
                {
                  case '1':
                    hero.clearObstacle(currentMap.grovnicks, 1);
                    break;
                  case '2':
                    hero.clearObstacle(currentMap.grovnicks, 2);
                    break;
                  case '3':
                    hero.clearObstacle(currentMap.grovnicks, 3);
                    break;
                  case '4':
                    hero.clearObstacle(currentMap.grovnicks, 4);
                    break;
                  case '5':
                    hero.clearObstacle(currentMap.grovnicks, 5);
                    break;
                }
              }
              break;

            case 3:
              {
                Tool * tool = dynamic_cast<Tool *>(current);
                //hero.addToolToInventory(toolPtr);
                //currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;

                if(tool && tool -> type == 3)
                {

                  //here the Tool class also calls the constructor for the Grovnick base class, and it should work, but doesnt!
                  //the Tool class makes a segfault on line 105, and then Grovnick says
                  //  tooltype and item_effectiveness does not exist in grovnick
                  Tool *toolptr = new Tool( current->y_axis,
                      tool->x_axis,
                      tool->cost,
                      tool->type,
                      tool->name,
                      tool->tool_type,           //in the Tool derived class
                      tool->item_effectiveness   //in the Tool derived class
                      );
                  hero.addToolToInventory(toolptr);
                  currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;
                }
                break;
              }

      	    case 4: //diamond
        	    {
        		    //Royal_Diamond * current = dynamic_cast<Royal_Diamond *>(current);
        		    hero.addWhiffles(1000000000); // add to bank account
        		    break;
        	    }

            case 6: //treasure chest
              {
                Treasure * chest = dynamic_cast<Treasure *>(current);
                hero.addWhiffles(chest->treasure);
                currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;
                ncursescontroller.displayMove(hero.whiffles, hero.energy);
                move((LINES/2)-1, ((COLS-30)/2)-1);
                break;
              }

            case 7: //ship
              {
                if(hero.whiffles >= current->cost)
                {
                  hero.spendWhiffles(current->cost);
                  currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;
                  ncursescontroller.displayMove(hero.whiffles, hero.energy);
                  hero.gainBoat();
                  move((LINES/2)-1, ((COLS-30)/2)-1);
                }
                break;
              }

            case 8: //binoculars
              {
                if(hero.whiffles >= current->cost)
                {
                  hero.spendWhiffles(current->cost);
                  currentMap.grovnicks[hero.yAxis][hero.xAxis] = NULL;
                  ncursescontroller.displayMove(hero.whiffles, hero.energy);
                  hero.gainBinoculars();
                  move((LINES/2)-1, ((COLS-30)/2)-1);
                }
                break;
              }

            default:
              break;
          }
        }
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

    if(hero.whiffles >= 1000000000) // end game with diamond
    {

		ncursescontroller.displayVictory();
		return 0;
    }

    Grovnick * temp = currentMap.grovnicks[cursory][cursorx];
    if(temp)
    {
      //need to set up a loop for display discovered grovnicks? How to display only discovered grovnicks? use discovered[128][128] instead of grovnicks[][]?
      Obstacle * obst = dynamic_cast<Obstacle *>(temp);
      if(obst)
      {
        if(obst->obs_type == 1)
          mvprintw(2, leftbuffer, " Obstacle: Tree");
        else if(obst->obs_type == 2)
          mvprintw(2, leftbuffer, " Obstacle: Boulder");
        mvprintw(3, leftbuffer, " Cost: %d", obst->cost);
      }

      Tool * a_tool = dynamic_cast<Tool *>(temp);
      if(a_tool)
      {
        mvprintw(2, leftbuffer, " Tool: %s", a_tool->name.data());
        mvprintw(3, leftbuffer, " Cost: %d", a_tool->cost);
        if(a_tool->tool_type == 1)
          mvprintw(4, leftbuffer, " Type: Axe");
        else if(a_tool->tool_type == 2)
          mvprintw(4, leftbuffer, " Type: Hammer");
        mvprintw(5, leftbuffer, " Effectiveness: %dX", a_tool->item_effectiveness);
      }

      Food * a_food = dynamic_cast<Food *>(temp);
      if(a_food)
      {
        mvprintw(2, leftbuffer, " Food: %s", a_food->name.data());
        mvprintw(3, leftbuffer, " Cost: %d", a_food->cost);
        mvprintw(4, leftbuffer, " Energy: %d", a_food->restore);
      }

      Treasure * trea = dynamic_cast<Treasure *>(temp);
      if(trea)
      {
        mvprintw(2, leftbuffer, " TREASURE!");
        mvprintw(3, leftbuffer, " Reward: %d", trea->treasure);
      }

      Royal_Diamond * royal = dynamic_cast<Royal_Diamond *>(temp);
      if(royal)
        mvprintw(2, leftbuffer, " Royal Diamond!!");

      Clue * a_clue = dynamic_cast<Clue *>(temp);
      if(a_clue)
        mvprintw(2, leftbuffer, " Clue: %s", a_clue->clue.data());

      Binoculars * binoc = dynamic_cast<Binoculars *>(temp);
      if(binoc)
        mvprintw(2, leftbuffer, " Binoculars!");

      Ship * a_ship = dynamic_cast<Ship *>(temp);
      if(a_ship)
        mvprintw(2, leftbuffer, " A ship!");
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

// character.cpp
//
// This files contains the character class.
//

#include "character.h"


int leftbuffer = COLS - 28;

Character::Character()
{
  yAxis = 1;
  xAxis = 1;
  energy = 102;
  whiffles = 1000;
  binoculars = false;
  boat = false;
  for(int i = 0; i < MAX_TOOLS; ++i)
  {
    toolbag[i] = NULL;
  }
}


Character::~Character()
{
}


int Character::checkEnergy()
{
  return energy;
}


void Character::addEnergy(int added)
{
  energy += added;
}


void Character::spendEnergy(int spent)
{
  energy -= spent;
}


int Character::checkWhiffles()
{
  return whiffles;
}


void Character::addWhiffles(int added)
{
  whiffles += added;
}


void Character::spendWhiffles(int spent)
{
  whiffles -= spent;
}

void Character::gainBinoculars()
{
  binoculars = true;
}


void Character::gainBoat()
{
  boat = false;
}


bool Character::hasBoat()
{
  if (boat) return true;

  else return false;
}


bool Character::hasBinoculars()
{
  if (binoculars) return true;

  else return false;
}

//the toolbag will only ever store tools.... so why typecasting?
//takes in a pointer to the address of the item since memory is allocated outside the function
bool Character::addToolToInventory(Tool *&item)
{
  int i = freeSpotInToolBag();
  bool isfull = isToolBagFull();
  if(i >= 0 && i < MAX_TOOLS) //check for valid range
  {
    if(isfull)
    {
      mvprintw(LINES-25, leftbuffer, " Your bag is full!");
      mvprintw(LINES-24, leftbuffer, " remove a tool!");
      printTools();
      char ch = getch();
      switch(ch)
      {
        case '1':
          dropToolFromToolbag(0);
          toolbag[i] = item;
          return true;
          break;
        case '2':
          dropToolFromToolbag(1);
          toolbag[i] = item;
          return true;
          break;
        case '3':
          dropToolFromToolbag(2);
          toolbag[i] = item;
          return true;
          break;
        case '4':
          dropToolFromToolbag(3);
          toolbag[i] = item;
          return true;
          break;
        case '5':
          dropToolFromToolbag(4);
          toolbag[i] = item;
          return true;
          break;
        default:
          mvprintw(LINES-30, leftbuffer, " You didnt drop any tools");
          break;
      }

    }
    else
    {
      toolbag[i] = item;
      return true;
    }

  }
  return false;
}

//returns the free index of the toolbag
int Character::freeSpotInToolBag()
{
  for(int i = 0; i < MAX_TOOLS; ++i)
  {
    if(!toolbag[i])
      return i; //index to add the tool to
  }
  return -1;  //no room!
}
void Character::dropToolFromToolbag(int whichtool)
{
  if(toolbag[whichtool])
  {
    //TODO: memory management because right now, its just bad practice
    toolbag[whichtool] = NULL;
  }
}

//clear a obstacle, takes in an obstacle class type object and a tool number
//from user selection
int Character::clearObstacle(Grovnick *grovnicks[128][128], int toolNumber)
{
  --toolNumber; //since the user is given 1 -> MAX_TOOLS, NOT 0 - MAX_TOOLS-1
  Obstacle *obstacle = dynamic_cast<Obstacle*>(grovnicks[yAxis][xAxis]);
  if(!obstacle)
    return -1;  //if the obstacle is not valid
  if(toolbag[toolNumber] == NULL)
    return -2;  //if the toolbag item is invalid

  //now obstacle AND tools should be valid, time to check if they match up
  if(toolbag[toolNumber]->type_match(*obstacle))
  {
    //now we know that the obstacle and tool match, 
    spendEnergy( (obstacle->cost)
                /(toolbag[toolNumber]->item_effectiveness)
        );
    //TODO some memory managment here!
    grovnicks[yAxis][xAxis] = NULL;
    return 1; //obstacle removed!
  }

  return 0; //obstacle and tool type did not match
}

void Character::printTools()
{
  for(int i = 0; i < MAX_TOOLS; ++i)
  {
    mvprintw(LINES-20, leftbuffer, " The tools you have are: ");
    if(toolbag[i])
      mvprintw(i+LINES-19, leftbuffer, " %d) %s\n", i+1, toolbag[i]->name.data());
  }
}

bool Character::isToolBagFull()
{
  for(int i = 0; i < MAX_TOOLS; ++i)
  {
    if(toolbag[i] == NULL)
      return false;
  }
  return false;
}

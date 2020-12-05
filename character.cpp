// character.cpp
//
// This files contains the character class.
//

#include "character.h"


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
  if(i >= 0 && i < MAX_TOOLS) //check for valid range
  {
    toolbag[i] = item;
    return true;
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

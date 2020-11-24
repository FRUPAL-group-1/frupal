// character.cpp
//
// This files contains the character class.
//

#include "character.h"


Character::Character()
{
	yAxis = 0;
	xAxis = 0;
	energy = 100;
	whiffles = 1000;
	binoculars = false;
	boat = false;
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

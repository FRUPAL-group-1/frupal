//CS300 Fall 2020
//Group 1
//grovnick.cpp
//implementation for grovnick, tool, obstacle, food, royal diamond, clue, and treasure classes
#include "grovnick.h"

//default constructor
Grovnick::Grovnick()
{
	y_axis = 0;
	x_axis = 0;
	cost = 0;
	type = 0;
	name = "";
}

//constructor with arguments
Grovnick::Grovnick(int y, int x, int cst, int tpe, string nme)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
}

//destructor
Grovnick::~Grovnick(){}

//checks location match
bool Grovnick::is_match(int x, int y)
{
	if(x_axis == x && y_axis == y)
		return true;
	else
		return false;
}

//default constructor
Food::Food():Grovnick()
{
	restore = 0;
	is_consumed = false;
}

//constructor with arguments
Food::Food(int y, int x, int cst, int tpe, string nme, int rstre, bool consumed):Grovnick(y, x, cst, tpe, nme)
{
	restore = rstre;
	is_consumed = consumed;
}

//deconstructor
Food::~Food(){}

//default constructor
Obstacle::Obstacle():Grovnick()
{
	obs_type = 0;
}

//constructor with arguments
Obstacle::Obstacle(int y, int x, int cst, int tpe, string nme, int obs_tpe):Grovnick(y, x, cst, tpe, nme)
{
	obs_type = obs_tpe;

}

//deconstructor
Obstacle::~Obstacle(){}

//default constructor
Tool::Tool():Grovnick()
{
	item_effectiveness = 0;
}

//have the Tool constructor call onto the base class constructor
Tool::Tool(int y, int x, int cst, int tpe, string nme, int tl_type, int effectiveness):Grovnick(y,x,cst,tpe,nme)
{
  //Let the constructor for the default class take care of making the parent
	/*
  y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
  */
	//initialization list instead?
	tool_type = tl_type;
	item_effectiveness = effectiveness;
}

//deconstructor
Tool::~Tool(){}

//check if tool and obstacle types match
bool Tool::type_match(Obstacle to_check)
{
	if(tool_type == to_check.obs_type)
		return true;
	else
		return false;
}

Royal_Diamond::Royal_Diamond()
{
	grand_prize = 0;
}

//constructor with arguments
Royal_Diamond::Royal_Diamond(int y, int x, int cst, int tpe, string nme, int prize):Grovnick(y, x, cst, tpe, nme)
{
	grand_prize = prize;
}

//deconstructor
Royal_Diamond::~Royal_Diamond(){}

//default constructor
Clue::Clue():Grovnick()
{
	clue = "";
	is_truthful = false;
}

//constructor with arguments
Clue::Clue(int y, int x, int cst, int tpe, string nme, string clu, bool truth):Grovnick(y, x, cst, tpe, nme)
{
	clue = clu;
	is_truthful = truth;
}

//deconstructor
Clue::~Clue(){}

//default constructor
Treasure::Treasure():Grovnick()
{
	treasure = 0;
}

//constructor with arguments
Treasure::Treasure(int y, int x, int cst, int tpe, string nme, int prize):Grovnick(y, x, cst, tpe, nme)
{
	treasure = prize;
}

//deconstructor
Treasure::~Treasure(){}

//default constructor
Ship::Ship():Grovnick(){}

//constructor with arguments
Ship::Ship(int y, int x, int cst, int tpe, string nme):Grovnick(y, x, cst, tpe, nme){}

//destructor
Ship::~Ship(){}

//default constructor
Binoculars::Binoculars():Grovnick(){}

//constructor with arguments
Binoculars::Binoculars(int y, int x, int cst, int tpe, string nme):Grovnick(y, x, cst, tpe, nme){}

//destructor
Binoculars::~Binoculars(){}

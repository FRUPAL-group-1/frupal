#ifndef GROVNICK_CPP
#define GROVNICK_CPP

//CS300 Fall 2020
//Group 1
//grovnick.cpp
//implementation for grovnick, tool, obstacle, food, royal diamond, clue, and treasure classes
#include "grovnick.h"

Grovnick::Grovnick()
{
	key = "";
	y_axis = 0;
	x_axis = 0;
	cost = 0;
	type = 0;
	//what to do for char sign?
	name = "";
}


Grovnick::Grovnick(string ky, int y, int x, int cst, int tpe, char sgn, string nme)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
}


Grovnick::~Grovnick()
{
	//strings count as dynamic memory and need to be deleted? fill
}


void Grovnick::display_on()
{
	//unsure how this interacts with ncurses; discuss with team
	if(type == 1)
		cout << "Food: " << name << endl;
	else if(type == 2)
		cout << "Obstacle: " << name << endl;
	else if(type == 3)
		cout << "Tool: " << name << endl;
	cout << "Price: " << cost << endl;
	cout << "Type: " << type << endl;
}


bool Grovnick::is_match(int x, int y)
{
	if(x_axis == x && y_axis == y)
		return true;
	else
		return false;
}


Food::Food() //initialization list in constructor?
{
	//TODO all the other stuff
	restore = 0;
	is_consumed = false;	
}


Food::Food(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int rstre, bool consumed)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;		//maybe should just set it to 1 for food instead? Similar for other classes?
	sign = sgn;
	name.assign(nme);
	//considered using initialization list but it would be so huge! maybe still do it?
	restore = rstre;
	is_consumed = consumed;
}


Food::~Food()
{
	//TODO fill
}


Obstacle::Obstacle()
{
	//same concerns as food: initialization list or...?
	obs_type = 0;
}


Obstacle::Obstacle(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int obs_tpe)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
	//initialization list instead?
	obs_type = obs_tpe;
}


Obstacle::~Obstacle()
{
	//TODO fill
}


Tool::Tool()
{
	//again, same concerns here about initialization list
	item_effectiveness = 0;	
}


Tool::Tool(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int tl_type, int effectiveness)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
	//initialization list instead?
	tool_type = tl_type;
	item_effectiveness = effectiveness;	
}


Tool::~Tool()
{
	//TODO fill
}


bool Tool::type_match(Obstacle to_check)
{
	if(tool_type == to_check.obs_type)
		return true;
	else
		return false;
}


Royal_Diamond::Royal_Diamond()
{
	//again, same concerns here about initialization list
	grand_prize = 0;
}


Royal_Diamond::Royal_Diamond(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int prize)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
	//initialization list instead?
	grand_prize = prize;
}


Royal_Diamond::~Royal_Diamond()
{
	//TODO fill
}
		

Clue::Clue()
{
	//again, same concerns here about initialization list
	clue = "";
	truthful = false;
}


Clue::Clue(string ky, int y, int x, int cst, int tpe, char sgn, string nme, string clu, bool truth)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
	//initialization list instead?
	clue.assign(clu);
	truthful = truth;
}


Clue::~Clue()
{
	//TODO fill
}


Treasure::Treasure()
{
	//again, same concerns here about initialization list
	treasure = 0;
}


Treasure::Treasure(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int prize)
{
	key.assign(ky);
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	sign = sgn;
	name.assign(nme);
	//initialization list instead?
	treasure = prize;
}


Treasure::~Treasure()
{
	//TODO fill
}

#endif  //GROVNICK_CPP

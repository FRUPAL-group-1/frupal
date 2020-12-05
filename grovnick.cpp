//CS300 Fall 2020
//Group 1
//grovnick.cpp
//implementation for grovnick, tool, obstacle, food, royal diamond, clue, and treasure classes
#include "grovnick.h"

Grovnick::Grovnick()
{
	y_axis = 0;
	x_axis = 0;
	cost = 0;
	type = 0;
	name = "";
}


Grovnick::Grovnick(int y, int x, int cst, int tpe, string nme)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
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


Food::Food(int y, int x, int cst, int tpe, string nme, int rstre, bool consumed)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;		//maybe should just set it to 1 for food instead? Similar for other classes?
	name = nme;
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


Obstacle::Obstacle(int y, int x, int cst, int tpe, string nme, int obs_tpe)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
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


Royal_Diamond::Royal_Diamond(int y, int x, int cst, int tpe, string nme, int prize)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
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
	is_truthful = false;
}


Clue::Clue(int y, int x, int cst, int tpe, string nme, string clu, bool truth)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
	//initialization list instead?
	clue = clu;
	is_truthful = truth;
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


Treasure::Treasure(int y, int x, int cst, int tpe, string nme, int prize)
{
	y_axis = y;
	x_axis = x;
	cost = cst;
	type = tpe;
	name = nme;
	//initialization list instead?
	treasure = prize;
}


Treasure::~Treasure()
{
	//TODO fill
}

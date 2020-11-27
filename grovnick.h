//CS300 Fall 2020
//Group 1
//grovnick.h
//prototypes for grovnick, tool, obstacle, food, royal diamond, clue, and treasure classes
/*
	int type guide
	0 = NULL or empty;
	1 = Food item;
	2 = Obstacle; Obstacle also has its own Obstacle type variable. To be cleared, Obstacle type must match Tool type
	3 = Tool; Tool also has its own Tool type variable. To clear Obstacle, Tool type must match Obstacle type
	4 = Royal Diamond;
	5 = Clue;
	6 = Treasure Chest
*/
#ifndef GROVNICK
#include <iostream>
#include <string.h>

using namespace std;

class Grovnick
{
	public:
		Grovnick();
		Grovnick(string ky, int y, int x, int cst, int tpe, char sgn, string nme);
		~Grovnick();
		void display_on();
		bool is_match(int x, int y);

	protected:
		string key;	//not sure what this is?
		int y_axis;
		int x_axis;
		int cost;
		int type;
		char sign;
		string name;

		//other functions and variables?
};

class Food: public Grovnick
{
	public:
		Food();
		Food(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int rstre, bool consumed);
		~Food();
		int restore;
		bool is_consumed;

};

class Obstacle: public Grovnick
{
	public:
		Obstacle();
		Obstacle(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int obs_tpe);
		~Obstacle();
		int obs_type;	//how many ints? different than grovnick::type?
		//obs_type == 1 for tree, 2 for boulder
};

class Tool: public Grovnick
{
	public:
		Tool();
		Tool(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int tl_tpe, int effectiveness);
		~Tool();
		bool type_match(Obstacle);
		int tool_type;  //different than grovnick::type?
		//tool_type == 1 for axe (for trees), 2 for hammer (for boulder); essentially just needs to match obstacle type
		int item_effectiveness;
		//doesn't need string name because inherited
};

class Royal_Diamond: public Grovnick
{
	public:
		Royal_Diamond();	
		Royal_Diamond(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int prize);
		~Royal_Diamond();

		int grand_prize; 


};

class Clue: public Grovnick
{
	public:
		Clue();
		Clue(string ky, int y, int x, int cst, int tpe, char sgn, string nme, string clu, bool truth);
		~Clue();

		string clue;
		bool truthful;
};

class Treasure: public Grovnick
{
	public:
		Treasure();
		Treasure(string ky, int y, int x, int cst, int tpe, char sgn, string nme, int prize);
		~Treasure();
	
		int treasure;
};
#endif //GROVNICK

#ifndef CHAR
#define CHAR

// character.h
//
// This is the header file for character.cpp.

#define MAX_TOOLS 5

#include <ncurses.h>
#include <string.h>
#include "grovnick.h"

using namespace std;

class Character
{
	public:
		Character();
		~Character();

		int checkEnergy();
		void addEnergy(int added);
		void spendEnergy(int spent);	

		int checkWhiffles();
		void addWhiffles(int added);
		void spendWhiffles(int spent);

		void gainBinoculars();
		void gainBoat();
		bool hasBoat();
		bool hasBinoculars();
    
    //functions pertaining to the toolbag
    bool addToolToInventory(Grovnick *item);
    int freeSpotInToolBag();
	
		int yAxis;
		int xAxis;
		int energy;
		int whiffles;

    Grovnick *toolbag[MAX_TOOLS];

	protected:

		bool binoculars;
		bool boat;
};

#endif

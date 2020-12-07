#ifndef CHAR
#define CHAR

// character.h
//
// This is the header file for character.cpp.

#define MAX_TOOLS 5

#include <ncurses.h>
#include <string.h>
#include "grovnick.h"
#include "map.h"

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
    bool addToolToInventory(Tool *&item);
    int freeSpotInToolBag();
    void dropToolFromToolbag(int whichtool);
    void printTools();
    bool isToolBagFull();
    
    //pass in the map for the grovnicks, then pass in a 0-MAX_TOOLS item to use
    int clearObstacle(Grovnick *grovnicks[128][128], int toolNumber);
	
		int yAxis;
		int xAxis;
		int energy;
		int whiffles;

    Tool *toolbag[MAX_TOOLS];

	protected:

		bool binoculars;
		bool boat;
};

#endif

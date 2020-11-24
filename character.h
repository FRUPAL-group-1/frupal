// character.h
//
// This is the header file for character.cpp.

#include <ncurses.h>
#include <string.h>

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
	
		int yAxis;
		int xAxis;
		int energy;
		int whiffles;

	protected:

		bool binoculars;
		bool boat;
};

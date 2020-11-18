// character.h
//
// This is the header file for character.cpp.


using namespace std;

class Character
{
	public:
		Character();
		~Character();

		int checkEnergy();
		void addEnergy(int added);
		int spendEnergy(int spent);	
		int checkWhiffles();
		int addWhiffles(int added);
		int spendWhiffles(int spent);

	protected:
		int yAxis;
		int xAxis;
		int energy;
		int whiffles;
		bool binoculars;
		bool boat;
};

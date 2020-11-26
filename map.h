//map.h
//#include "grovnick.h"
#include <fstream>
#include <string>

class Map
{
	public:
		Map();
		~Map();

		int initializeMap();

		bool editTile(char tileType, int x, int y);

		char map[128][128];
		int discovered[128][128];
//		Grovnick grovnicks[128][128];

};

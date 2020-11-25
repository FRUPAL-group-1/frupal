//map.h
#include "locations.h"
#include <fstream>

class Map
{
	public:
		Map();
		~Map();

		Locations grovnicks; // ex usage: grovnicks.get(1, 20);

		int initializeMap(string fileName);

		bool editTile(char tileType, int x, int y);

		char map[128][128];
		char discovered[128][128];

};

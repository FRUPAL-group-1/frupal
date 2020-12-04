#ifndef MAP
#define MAP

//map.h
#include "grovnick.h"
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>

class Map
{
	public:
		Map();
		~Map();

		int initializeMap();
		int initializeGrovnicks();

		bool editTile(char tileType, int x, int y);

		char map[128][128];
		int discovered[128][128];
		Grovnick * grovnicks[128][128];

	private:
		void setGrovnick(Grovnick * ptr, int x, int y);	
};

#endif //MAP

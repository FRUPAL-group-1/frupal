//map.h
class Map
{
	public:
		Map();
		~Map();

<<<<<<< HEAD
		Locations grovnicks; // ex usage: grovnicks.get(1, 20);

		void initializeMap(string fileName);
=======
		int initializeMap(string fileName);
>>>>>>> 0a9bd8bf868a06dcc1ea09d55a122714f14f1895
		bool editTile(char tileType, int x, int y);

		char map[128][128];
		char discovered[128][128];

};

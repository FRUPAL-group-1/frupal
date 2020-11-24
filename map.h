//map.h
class Map
{
	public:
		Map();
		~Map();

		void initializeMap(string fileName);
		bool editTile(char tileType, int x, int y);

		char map[128][128];
		char discovered[128][128];

};
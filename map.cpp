#ifndef MAP_CPP
#define MAP_CPP

//map.cpp
#include "map.h"
using namespace std;

//default constructor
Map::Map()
{

}

//deconstructor
Map::~Map()
{

}

int Map::initializeMap()
{
  for(int i = 0; i < 128; i++){
    for(int j = 0; j < 128; j++){
      discovered[i][j] = 0;
    }
  }
  discovered[0][127] = 0;

  ifstream in;
  in.open("map.txt");
  if(in.is_open()){
    for(int y = 0; y < 128; y++){
      for(int x = 0; x < 128; x++){
        in >> map[y][x];
      }
    }
    in.close();
  } else {
    return 1;
  }
  return 0;
}

bool Map::editTile(char tileType, int x, int y)
{
  if(x < 0 || x > 127 || y < 0 || y > 127)
    return false;
  map[y][x] = tileType;
  return true;
}


// csv format
// type, x, y, cost, name :: additional fields specific to type

int Map::initializeGrovnicks()
{

  ifstream in;
  in.open("grovnicks.csv");

  while (in.good()){
    string line, cell, type;
    std::vector<string> values;

    getline (in, line);
    stringstream s(line);

    while(s.good()) {
      getline(s, col, ',');
      values.push_back(cell);
    }

    string type = values[0];
    int x = s_toi(values[1]);
    int y = s_toi(values[2]);
    int cst = s_toi(values[3]);
    string name = values[4];

    switch(type) {
      case "food":
        int rstre = s_toi(values[5]);

        Grovnick * ptr = new Food(y, x, cst, 1, name, rstre, false);
        setGrovnick(ptr, x, y);

        break;
      case "obstacle":
        int obs_type = s_toi(values[5]);

        Grovnick * ptr = new Obstacle(y, x, cst, 2, name, obs_type);
        setGrovnick(ptr, x, y);

        break;
      case "tool":
        // code block
        int tool_type = s_toi(values[5]);
        int efectivness = s_toi(values[6]);

        Grovnick * ptr = new Tool(y, x, cst, 3, name, tool_type, effectiveness);
        setGrovnick(ptr, x, y);

        break;
      case "royal_diamond":
        int prize = s_toi(values[5]);

        Grovnick * ptr = new Royal_Diamond(y, x, cst, 4, name, prize);
        setGrovnick(ptr, x, y);

        break;
      case "clue":
        string clue = values[5];
        bool truth = values[6] == "true";

        Grovnick * ptr = new Clue(y, x, cst, 5, name, clue, truth);
        setGrovnick(ptr, x, y);
        
        break;
      case "treasure":
        int prize = s_toi(values[5]);

        Grovnick * ptr = new Treasure(y, x, cst, 6, name, prize);
        setGrovnick(ptr, x, y);

        break;
      default: // skip
    }

  }

}

void Map::setGrovnick(Grovnick * ptr, int x, int y)
{
  if(grovnicks[x][y] == NULL) {
    map[x][y] = ptr;
  }
  // else ...
}


#endif //MAP_CPP

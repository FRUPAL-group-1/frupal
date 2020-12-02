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
/*
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

    switch(values[0]) {
      case "food":
        // code block
        int y = s_toi(values[2]);
        int x = s_toi(values[1]);
        int cst = s_toi(values[3]);
        int rstre = s_toi(values[5]);

        Grovnick * ptr = new Food(y, x, cst, 1, values[4], rstre, false);

        map[x][y] = ptr;

        break;
      case "obstacle":
        // code block
        break;
      case "obstacle":
        // code block
        break;
      case "tool":
        // code block
        break;
      case "royal_diamond":
        // code block
        break;
      case "clue":
        // code block
        break;
      case "treasure":
        // code block
        break;
      default:
        // skip
    }

  }

}
*/

#endif //MAP_CPP

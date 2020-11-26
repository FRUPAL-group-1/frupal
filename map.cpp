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

#endif //MAP_CPP

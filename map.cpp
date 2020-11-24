//map.cpp
#include "map.h"

//default constructor
map::Map()
{
  discovered = {{0}};
}

//deconstructor
map::~Map()
{

}

int map::initializeMap(string fileName)
{
  ifstream in;
  in.open(fileName);
  if(in.is_open()){
    for(int y = 0; y < 128; y++){
      for(int x = 0; x < 128; x++){
        in >> map[y][x];
      }
    }
    in.close();
    return 0;
  } else {
    return 1;
  }
}

bool map::editTile(char tileType, int x, int y)
{
  if(x < 0 || x > 127 || y < 0 || y > 127)
    return false;
  map[y][x] = tileType;
  return true;
}

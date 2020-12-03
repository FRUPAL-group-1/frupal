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
    string row;
    vector<string> values;

    getline (in, row);
    stringstream s(row);

    while(s.good()) {
      string cell;
      getline(s, cell, ',');
      values.push_back(cell);
    }
    
    int type = stoi(values[0]);
    int x = stoi(values[1]);
    int y = stoi(values[2]);
    int cst = stoi(values[3]);
    string name = values[4];

    switch(type) {
      case 1:
      {
        int restore = stoi(values[5]);

        Grovnick * foodPtr = new Food(y, x, cst, 1, name, restore, false);
        setGrovnick(foodPtr, x, y);
      } break;
      case 2:
      {
        int obs_type = stoi(values[5]);

        Grovnick * obstaclePtr = new Obstacle(y, x, cst, 2, name, obs_type);
        setGrovnick(obstaclePtr, x, y);
      } break;
      case 3:
      {
        int tool_type = stoi(values[5]);
        int effectiveness = stoi(values[6]);

        Grovnick * toolPtr = new Tool(y, x, cst, 3, name, tool_type, effectiveness);
        setGrovnick(toolPtr, x, y);
      } break;
      case 4:
      {
        int prize = stoi(values[5]);

        Grovnick * royalDiamondPtr = new Royal_Diamond(y, x, cst, 4, name, prize);
        setGrovnick(royalDiamondPtr, x, y);
      } break;
      case 5:
      {
        string clue = values[5];
        bool truth = values[6] == "true";

        Grovnick * cluePtr = new Clue(y, x, cst, 5, name, clue, truth);
        setGrovnick(cluePtr, x, y);
      } break;
      case 6:
      {
        int prize2 = stoi(values[5]);

        Grovnick * treasurePtr = new Treasure(y, x, cst, 6, name, prize2);
        setGrovnick(treasurePtr, x, y);
      } break;
    }
    

  }

  in.close();
  return 1;

}

void Map::setGrovnick(Grovnick * ptr, int x, int y)
{
  if(grovnicks[x][y] == NULL) {
    grovnicks[x][y] = ptr;
  }
  // else ...
}


#endif //MAP_CPP

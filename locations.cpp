// C. Gunnar Rosenberg
// Locations Class

#include "locations.cpp"

// takes x and y cords and returns corresponding grovinick
Grovnick Locations::get(int x, int y){
  string key = keyGen(x, y);

  auto res = grovnicks.find({key});

  return res->second;
}

// allows placement of grovnick via x and y cords
bool Locations::set(int x, int y, Grovnick obj){
  string key = keyGen(x, y);
  
  auto status = grovnicks.insert({key, obj}); // cast auto here?

  if (!status.second){ // try erasing any existing data and overwriting
    grovnicks.erase(key);

    auto retry = grovnicks.insert({key, obj});

    return retry.second;
  }

  return true;
}

// allows deletion of grovnicks via x and y cords
void Locations::destroy(int x, int y){
  string key = keyGen(x, y);

  grovnicks.erase({key});
}

// creates key from x and y cords
string Locations::keyGen(int x, int y){
  return (to_string(x) + "|" + to_string(y));
}
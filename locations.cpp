// C. Gunnar Rosenberg
// Locations Class

#include "locations.cpp"



any Locations::get(string key){
  auto res = grovnicks.find(key);
  return res->second;
}

bool Locations::set(string key, any grovnick){
  // cast auto here
  auto status = grovnicks.insert({key, grovnick});

  if (!status.second){
    grovnicks.erase(key);
    auto retry = grovnicks.insert({key, grovnick});
    return retry.second;
  }

  return true;
}

void Locations::destroy(string key){
  grovnicks.erase({key});
}

// C. Gunnar Rosenberg
// Locations

#include <string.h>
#include <map>
#include <any>
#include "grovnick.h"
using namespace std;

class Locations {
    map<string, Grovnick> grovnicks;
    string keyGen(int x, int y);

  public:
    Grovnick get(int x, int y);
    bool set(int x, int y, Grovnick obj);	
    void destroy(int x, int y);

};


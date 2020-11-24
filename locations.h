// C. Gunnar Rosenberg
// Locations

#include <string.h>
#include <map>
#include <any>
using namespace std;

class Locations {
  protected: 
    map<string, any> grovnicks;

  public:
    any get(string key);
    bool set(string key, any grovnick);	
    void destroy(string key);

};


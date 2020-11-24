# FRUPAL (Group 1)
...

### Members
- Carl Gunnar Rosenberg
- Maksim Semchuk
- Jonatham Rivera
- Tareq Jallad
- Natasha Needham



#############
Locations class:
  This class is a map of the Frupal kingdom.
  -Get function returns what is in the area, with an argument of string passed in as a key.
  -Set function takes in a string as a key and a grovnik to set to the area.
  -Destroy function takes in a key, then removes the grovnik


Charachter class:
  This class will is responsible for managing everything related to the character class.
  Every private member has proper set and get functions for the private data members so I will only
  cover the private data.


  -yAxis, xAxis both hold the data for where the characte is located.
  -Energy is the remaining energy a character remains
  -whiffles is how many wiffles (currency in Fruplandia)
  -binoculars is a bool, that will switch to true, after the character finds binoculars.
  -a boat will allow the character to traverse water (blue squares), it is also a bool.

NcursesController class:
  This class is reponsible for doing the ncurses map, and managing the colors on the screen.
  -Discover function, allows the map to get rid of "fog of war" from the map, leaving it visible.
    it uses a radius around character to uncover the map.
    the discover function takes in a hero x,y, and the discovered map to update.
  -DisplayFrame function takes in the map, the function, a hero x,y and the discoverd map.
    the function then goes through the cases and calculates the character movement.


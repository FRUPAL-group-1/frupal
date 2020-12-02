#Group 1 Makefile for FRUPAL
#CS300 Fall 2020
#ncurses

CPP = g++
CPPFLAGS = -Wall -Werror -g
TARGET = frupal
SRCS = NcursesController.cpp character.cpp gameController.cpp grovnick.cpp main.cpp map.cpp 

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(SRCS) -lncurses

clean:
	-rm -f $(TARGET)
zip:
	zip group1FRUPAL.zip Makefile *.cpp *.h README.md *.txt *.csv

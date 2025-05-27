// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#ifndef WORLD_H // instantiates the class once
#define WORLD_H // defines World class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes ifstream and ofstream
#include <ctime> // includes time
#include <cstdlib> // includes standard library functions
#include "Level.h" // includes contents from Level.h
#include "Mario.h" // includes contents from Mario.h

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class World { // defines class body

    private: // private variables
        int levels; // number of levels in world (L)
        int levelLength; // length of each level in world (N)
        Mario mario; // a mario object for Mario methods
        Level** world; // 'world' is a dynamically allocated array of Level objects
        // each Level has its own features with different positions
        // all Levels have a warp pipe except the last

    public:
        World(int* worldArr, std::string outFileName); // overloaded constructor
        // also plays the game!!!!!
        ~World(); // default destructor

};

#endif // end of class definition
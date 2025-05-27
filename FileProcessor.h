// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#ifndef FILEPROCESSOR_H // instantiates the class once
#define FILEPROCESSOR_H // defines FileProcessor class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes if::stream and of::stream
#include <sstream> // includes string stream for numbers in txt
#include "World.h" // includes contents from World.h
#include "Level.h" // includes contents from Level.h
#include "Mario.h" // includes contents from Mario.h

class FileProcessor { // defines class body

    public:
        FileProcessor(); // default constructor
        ~FileProcessor(); // default destructor
        int* readFiles(std::string inFileName); // a public void method that reads through the txt file inFileName
        // returns an array of integers that is used as a parameter in World to set up the levels and play the game
};

#endif // end of class definition
// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#ifndef LEVEL_H // instantiates class once
#define LEVEL_H // defines Level class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <cstdlib> // includes standard library functions
#include "Mario.h" // includes Mario class

class Level { // defines class body

    private: // private variables
        int length; // length of the Level's grid (N)
        char** grid; // a grid of characters NxN dimensions
        int marioRow; // Mario's row position
        int marioCol; // Mario's column position
        int coinPercent; // the approximate percentage of the positions with coins
        int noPercent; // the approximate percentage of the positions with nothing
        int goombaPercent; // the approximate percentage of the positions with Goombas
        int koopaPercent; // the approximate percentage of the positions with Koopas
        int mushroomPercent; // the approximate percentage of the positions with mushrooms
        void moveUp(); // allows Mario to move 1 position up the grid
        void moveDown(); // allows Mario to move 1 position down the grid
        void goRight(); // allows Mario to move 1 position right of the grid
        void goLeft(); // allows Mario to move 1 position left of the grid

    public:
        Level(int* worldArr); // default constructor
        ~Level(); // default destructor
        void buildLevel(); // a public void method that builds the contents of each level in world
        void setMarioPosition(int row, int col); // assigns Mario random a row and column based on the grid's dimensions
        char getCharacter(int row, int col); // returns each character in the grid
        void setNothing(int row, int col); // sets char to 'x'
        int getMarioRow(); // returns Mario's row # as an int
        int getMarioCol(); // returns Mario's col # as an int
        // this method will most likely be used in FileProcessor when playing the game
        void addWarpPipe(); // randomly adds a warp pipe in grid
        std::string moveOn(int dir); // uses private methods to randomly move Mario when he chooses
        // returns an int indicating which movement he goes

};

#endif // ends class definition
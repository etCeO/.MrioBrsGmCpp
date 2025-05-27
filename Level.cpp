// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <cstdlib> // includes standard library functions
#include "Level.h" // includes contents from header file
#include "Mario.h" // includes Mario class

// CONSTRUCTORS AND DESTRUCTORS

Level::Level(int* worldArr) { // overloaded constructor
    // all values default to 0 until read from file processor
    length = worldArr[1]; // length of grid dimension
    // an array of chars for each char array of size length
    marioRow = 0; // Mario's random row position
    marioCol = 0; // Mario's random column position
    coinPercent = worldArr[3]; // proportion of coins in grid
    noPercent = worldArr[4]; // proportion of nothing in grid
    goombaPercent = worldArr[5]; // proportion of Goombas in grid
    koopaPercent = worldArr[6]; // proportion of Koopas in grid
    mushroomPercent = worldArr[7]; // proportion of mushrooms in grid
    grid = new char*[length]; // a new grid of chars is allocated with length
    for (int i = 0; i < length; i++) {
        grid[i] = new char[length];
        // each position is assigned with an array
    }
}

Level::~Level() { // default destructor
    for (int i = 0; i < length; i++) {
        delete[] grid[i];
        // deallocates each char array in grid
    }
    delete[] grid;
    // deallocates grid remainder
}

// PRIVATE METHODS

void Level::moveUp() {
// a private void method for moving up in the grid
    if (marioRow == 0) { // if Mario is in row 0
        marioRow = length - 1;
        // he moves "up" to the last row
    }
    else { // decrements row position if not 0
        --marioRow; 
    }
}

void Level::moveDown() {
// a private void method for moving down in the grid
    if (marioRow == length - 1) { // if Mario is in the last row
        marioRow = 0;
        // he moves "down" to the first row
    }
    else { // increments row position if not last
        ++marioRow;
    }
}

void Level::goRight() {
// a public void method for going right in the grid
    if (marioCol == length - 1) { // if Mario is in the last column
        marioCol = 0;
        // he goes "right" to the first column
    }
    else { // increments col position if not last
        ++marioCol;
    }
}

void Level::goLeft() {
// a private void method for going left in the grid
    if (marioCol == 0) { // if Mario is in the first column
        marioCol = length - 1;
        // he goes "left" to the last column
    }
    else { // decrements col position if not first
        --marioCol;
    }
}

// PUBLIC METHODS

    // SETTERS

void Level::buildLevel() {
// a public void method that sets the contents of chars in world from the constructor
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
        // for every element in grid
            int randNum = std::rand() % 100;
            // pull a random number
            if (randNum < coinPercent) {
                // if the random number is the proportion of coins
                grid[i][j] = 'c';
                // assign a coin
            }
            else if (randNum < coinPercent + noPercent) {
                // if the random number is the proportion of nothing
                grid[i][j] = 'x';
                // assign nothing
            }
            else if (randNum < coinPercent + noPercent + goombaPercent) {
                // if the random number is the proportion of goombas
                grid[i][j] = 'g';
                // assign a goomba
            }
            else if (randNum < coinPercent + noPercent + goombaPercent + koopaPercent) {
                // if the random number is the proportion of koopas
                grid[i][j] = 'k';
                // assign a koopa
            }
            else if (randNum < coinPercent + noPercent + goombaPercent + koopaPercent + mushroomPercent) {
                // if the random number is the proportion of mushrooms
                grid[i][j] = 'm';
                // assign a mushroom
            }
        }
    }
    int randomRow = std::rand() % length;
    int randomCol = std::rand() % length;
    grid[randomRow][randomCol] = 'b'; // a boss is randomly assigned anywhere in the level
}

void Level::setMarioPosition(int row, int col) {
// a public void method for assigning Mario's random position
// this method is called each time he starts a new level
    marioRow = row;
    marioCol = col;
    // rows and columns are assigned #s 0-length
}

    // GETTERS

char Level::getCharacter(int row, int col) {
// a public char method for returning each character in a level
    return grid[row][col];
}

void Level::setNothing(int row, int col) {
// a public void method for setting a char in Level to nothing
    grid[row][col] = 'x';
}

int Level::getMarioRow() {
// a public int method that returns Mario's row
    return marioRow;
}

int Level::getMarioCol() {
// a public int method that returns Mario's column
    return marioCol;
}

    // GAME FUNCTIONS

void Level::addWarpPipe() {
// a public void method for adding warp pipes in random positions in levels
        int randomRow = std::rand() % length;
        int randomCol = std::rand() % length;
        // generate a random row and column
        while (grid[randomRow][randomCol] == 'b') {
            // while the random position has a boss
            randomRow = std::rand() % length;
            randomCol = std::rand() % length;
            // assign the character to a new positon
        }
        grid[randomRow][randomCol] = 'w';
        // ward pipe 'w' is added into a random position
        // rows and columns numbered 0-length
        // this method will be called in World when building Levels
        // every level except last will have a warp pipe
}

std::string Level::moveOn(int dir) {
// a public void method for randomizing Mario's movements in the game
    std::string direction;
    // Mario's direction choice will be a random number 0-3
    switch(dir) {
    // switch-case for determining his movements
        case 0:
        // if direction is 0 he goes up the grid
            moveUp();
            direction = "UP";
            break;
        case 1:
        // if direction is 1 he goes down the grid
            moveDown();
            direction = "DOWN";
            break;
        case 2:
        // if direction is 2 he goes to the right of the grid
            goRight();
            direction = "RIGHT";
            break;
        case 3:
        // if direction is 3 he goes to the left of the grid
            goLeft();
            direction = "LEFT";
            break;
        default:
        // default for proper structure
            break;
    }
    return direction; // returns Mario's direction number
}


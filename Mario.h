// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#ifndef MARIO_H // instantiates class once
#define MARIO_H // defines Mario class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <cstdlib> // includes standard library functions

class Mario { // defines class body 

    private: // private variables 
        int lives; // number of lives Mario has
        int coins; // number of coins Mario has
        int powerLevel; // Mario's powerlevels (0-2)
        int defeatedEnemies; // number of Mario's enemies defeated in a single level

    public: // public methods and constructors
        Mario(); // default constructor
        ~Mario(); // default destructor
        void collectCoin(); // adds a coin to Mario's inventory and another life when he has 20 coins      
        void magicMushroom(); // increases Mario's power level by 1 when he encounters a mushroom
        void setLives(int l); // sets the number of Mario's current lives when the txt file is read
        int getLives(); // returns Mario's lives
        int getCoins(); // returns Mario's coins
        int getPowerLevel(); // returns Mario's power level
        bool defeatGoomba(); // Mario fighting a Goomba
        bool defeatKoopa(); // Mario fighting a Koopa
        bool defeatBoss(); // Mario fighting the boss

};

#endif // ends class definition
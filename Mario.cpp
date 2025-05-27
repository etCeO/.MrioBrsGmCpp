// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <cstdlib> // includes standard library functions
#include "Mario.h" // includes contents from header file

// CONSTRUCTORS AND DESTRUCTORS

Mario::Mario() : lives(0), coins(0), powerLevel(0), defeatedEnemies(0) {};
// Mario naturally starts out with 0 coins at a power level of 0 in the new World he's assigned
// lives is assigned to a default value of 0 until txt file is read

Mario::~Mario(){}; // default destructor

// PUBLIC METHODS

void Mario::collectCoin() {
    // a public void method that adds a coin to Mario's inventory
    ++coins;
    // also adds another life depending on the # of coins he has
    if (coins % 20 == 0) {
    // for every 20 coins Mario collects
        ++lives; // lives +1
        defeatedEnemies = 0; // defeated enemies resets when he earns another life
        coins = 0; // number of coins resets to 0
    }
}

void Mario::magicMushroom() {
// a public void method that increments Mario's power levels when he encounters a mushroom
// since Mario's maximum power level is 2, this method only works if Mario's power level is less than 2
    if (powerLevel < 2) {
        ++powerLevel; // powerLevel +1
    }
}

void Mario::setLives(int l) { // public void method that sets Mario's lives from the txt file
    lives = l; // lives is assigned to int parameter l
}

int Mario::getLives() {
    // a public int method that returns Mario's lives
    return lives;
}

int Mario::getCoins() {
    // a public int method that returns Mario's coins
    return coins;
}

int Mario::getPowerLevel() {
    // a public int method that returns Mario's power level
    return powerLevel;
}

bool Mario::defeatGoomba() {
// a public bool method that represents a simulation of Mario fighting a Goomba
// returns true when he wins and false when he loses
    int chance = std::rand() % 100; // Mario's probability at winning
    // chance is a random number in range 0-99
    if (chance < 80) {
        // Mario has an 80% chance at defeating a Goomba
        // if his chance is in 0-79, he wins
        ++defeatedEnemies; // add this enemy to his defeated enemies
        if (defeatedEnemies % 7 == 0) { // if Mario defeats 7 enemies in the same life
            ++lives; // he gains another life
            defeatedEnemies = 0; // his defeated enemies resets
        }
        return true;
    }
    else {
        // when he loses, there are different consequences
        if (powerLevel == 0) {
            // if his power level is still 0
            --lives; // he loses a life
            defeatedEnemies = 0; // his defeated enemies resets
            return false;
        }
        else {
            // if his power level is 1 or 2
            --powerLevel; // he loses a power level
            return false;
        }
    }
}

bool Mario::defeatKoopa() {
// a public bool method that represents a simulation of Mario fighting a Koopa
// returns true when he wins and false when he loses
    int chance = std::rand() % 100; // Mario's probability at winning
    // chance is a random number in range 0-99
    if (chance < 65) {
        // Mario has a 65% chance at defeating a Koopa
        // if his chance is in 0-64, he wins
        ++defeatedEnemies; // add this enemy to his defeated enemies
        if (defeatedEnemies % 7 == 0) { // if Mario defeats 7 enemies in the same life
            ++lives; // he gains another life
            defeatedEnemies = 0; // his defeated enemies resets
        }
        return true;
    }
    else {
        // when he loses, there are different consequences
        if (powerLevel == 0) {
            // if his power level is still 0
            --lives; // he loses a life
            defeatedEnemies = 0; // his defeated enemies resets
            return false;
        }
        else {
            // if his power level is 1 or 2
            --powerLevel; // he loses a power level
            return false;
        }
    }
}

bool Mario::defeatBoss() {
// a public bool method that represents a simulation of Mario fighting a Boss
// returns true when he wins and false when he loses
    int chance = std::rand() % 100; // Mario's probability at winning
    // chance is a random number in range 0-99
    if (chance < 50) {
        // Mario has a 50% chance at defeating a Boss
        // if his chance is in 0-49, he wins
        ++defeatedEnemies; // add this enemy to his defeated enemies
        if (defeatedEnemies % 7 == 0) { // if Mario defeats 7 enemies in the same life
            ++lives; // he gains another life
            defeatedEnemies = 0; // his defeated enemies resets
        }
        return true;
    }
    else {
        // when he loses, there are different consequences
        if (powerLevel == 0 || powerLevel == 1) {
            // if his power level is at 0 or 1
            --lives; // he loses a life
            defeatedEnemies = 0; // his defeated enemies resets
            return false;
        }
        else {
            // if his power level is 2
            powerLevel -= 2; // he loses 2 power levels          
            return false;
        }
    }
}

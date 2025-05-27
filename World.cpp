// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes ifstream and ofstream
#include <ctime> // includes time
#include <cstdlib> // includes standard libary functions
#include "World.h" // includes contents from header file
#include "Level.h" // includes Level class
#include "Mario.h" // includes Mario class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

// CONSTRUCTORS AND DESTRUCTORS

World::World(int* worldArr, std::string outFileName) { // default constructor
// begins world as a placeholder until read from the txt in build method
    levels = worldArr[0]; // number of levels in world
    levelLength = worldArr[1]; // a each level's dimension
    Mario mario; // a mario object is created
    mario.setLives(worldArr[2]); // mario's lives set
    Level** world = new Level*[levels]; // an array of dynamically allocated levels called world is declared
    for (int i = 0; i < levels; i++) {
        // for every space in world
        world[i] = new Level(worldArr);
        world[i]->buildLevel();
        // create a new level
    }
    for (int i = 0; i < levels - 1; i++) {
        // for all levels in world except the last
        world[i]->addWarpPipe();
        // add a warp pipe
    }
    int marioLevel = 0; // an int that keeps track of Mario's level index
    int marioLives = mario.getLives(); // an int for Mario's lives
    int marioPowerLevel = mario.getPowerLevel(); // an int for Mario's power levels
    int marioCoins = mario.getCoins(); // an int for Mario's coins
    int dir; // a randomized int for Mario's next direction
    std::string nextDir; // an string for outFile and cout
    int row = -1; // a variable for Mario's row (assigned to -1 to prevent printing H first time)
    int col = -1; // a variable for Mario's row (assigned to -1 to prevent printing H first time)
    int firstRow; // Mario's first row in a level
    int firstCol; // Mario's first column in a level
    bool defeatedGoomba; // a bool for Mario's status on defeating a goomba
    bool defeatedKoopa; // a bool for Mario's status on defeating a koopa
    bool defeatedBoss; // a bool for Mario;s status on defeating a boss
    bool finishedGame = false; // a boolean for if the game is done or not
    bool gameWin = false; // a boolean for if Mario wins the game or not
    int turn = 0; // an int keeping track of Mario's turns in a single level
    // NOTE: all ++turn does is make sure Mario's turn is not his first
    // this ensures setMario() method is not called every time he's in a level

    std::ofstream outFile(outFileName); 

    if (outFile.is_open()) {

        while (!finishedGame && marioLives > 0) { // while the game is not over and mario is alive, game play proceeds
        // writing the Levels
            for (int x = 0; x < levels; x++) {
                // for all Levels in the world array
                cout << "   " << x << endl;
                cout << "-------" << endl;
                outFile << "   " << x << endl;
                outFile << "-------" << endl;
                for (int i = 0; i < levelLength; i++) {
                    for (int j = 0; j < levelLength; j++) {
                        // for all characters in each level array
                        if (i == row && j == col && turn != 0 && x == marioLevel) {
                            // if mario's row and col match and it is not his first turn, in the level replace his position with H
                            cout << "H ";
                            outFile << "H ";
                        }
                        else {
                            cout << world[x]->getCharacter(i, j) << " ";
                            outFile << world[x]->getCharacter(i, j) << " ";
                            // print the character and write it to the new txt file
                        }
                    }
                    cout << endl;
                    outFile << endl;
                        // newlines for neatness and dimension picture
                }
                cout << "===================" << endl;
                outFile << "===================" << endl;
                // spacings for each Level displayed
            }                
                if (turn == 0) { // if Mario is on his first turn in a level
                    firstRow = std::rand() % levelLength;
                    firstCol = std::rand() % levelLength;
                    world[marioLevel]->setMarioPosition(firstRow, firstCol); // randomize his first position
                }
                row = world[marioLevel]->getMarioRow(); // an int for Mario's current row in level
                col = world[marioLevel]->getMarioCol(); // an int for Mario's current column in level
                char position = world[marioLevel]->getCharacter(row, col); // retrieves the status of his position
                // output beginning status, including his position and power level
                cout << "Level: " << marioLevel << ". Mario is at position: (" << row << ", " << col << "). Mario is at power level" << endl;
                cout << marioPowerLevel << ". Mario ";
                outFile << "Level: " << marioLevel << ". Mario is at position: (" << row << ", " << col << "). Mario is at power level" << endl;
                outFile << marioPowerLevel << ". Mario ";
                switch (position) { // in the case Mario's position is...
                    case 'x': // nothing
                        cout << "visited an empty space. Mario has " << marioLives << " lives left. Mario" << endl;
                        cout << "has " << marioCoins << " coins. ";
                        outFile << "visited an empty space. Mario has " << marioLives << " lives left. Mario" << endl;
                        outFile << "has " << marioCoins << " coins. ";
                        dir = std::rand() % 4;
                        nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                        cout << "Mario will move " << nextDir << "." << endl;
                        outFile << "Mario will move " << nextDir << "." << endl;
                        ++turn;
                        break;
                    case 'c': // a coin
                        cout << "collected a coin. Mario has " << marioLives << " lives left. Mario" << endl;
                        outFile << "collected a coin. Mario has " << marioLives << " lives left. Mario" << endl;
                        mario.collectCoin(); // let Mario collect his coin
                        marioCoins = mario.getCoins();
                        cout << "has " << marioCoins << " coins. ";
                        outFile << "has " << marioCoins << " coins. ";
                        world[marioLevel]->setNothing(row, col); // set this position to nothing
                        dir = std::rand() % 4;
                        nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                        cout << "Mario will move " << nextDir << "." << endl;
                        outFile << "Mario will move " << nextDir << "." << endl;
                        ++turn;
                        break;
                    case 'm': // a mushroom
                        cout << "ate a mushroom. Mario has " << marioLives << " lives left. Mario" << endl;
                        outFile << "ate a mushroom. Mario has " << marioLives << " lives left. Mario" << endl;
                        mario.magicMushroom(); // let Mario interact with the mushroom
                        cout << "has " << marioCoins << " coins. ";
                        outFile << "has " << marioCoins << " coins. ";
                        world[marioLevel]->setNothing(row, col); // set this position to nothing
                        dir = std::rand() % 4;
                        nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                        cout << "Mario will move " << nextDir << "." << endl;
                        outFile << "Mario will move " << nextDir << "." << endl;
                        ++turn;
                        break;
                    case 'g': // a goomba
                    // proceed with regular rules of combat
                        cout << "encountered a goomba and ";
                        outFile << "encountered a goomba and ";
                        marioPowerLevel = mario.getPowerLevel(); // an int for Mario's power level
                        defeatedGoomba = mario.defeatGoomba(); // a bool for if Mario defeats him or not
                        marioLives = mario.getLives(); // check Mario's number of lives
                        if (defeatedGoomba) { // if the Goomba is defeated
                            cout << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                            cout << "has " << marioCoins << " coins. ";
                            outFile << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                            outFile << "has " << marioCoins << " coins. ";
                            world[marioLevel]->setNothing(row, col); // set this position to nothing
                            dir = std::rand() % 4;
                            nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                            cout << "Mario will move " << nextDir << "." << endl;
                            outFile << "Mario will move " << nextDir << "." << endl;
                            ++turn;
                        }
                        else { // if Mario lost
                            if (marioPowerLevel == 0) { // if Mario's power level is 0
                                while (!defeatedGoomba && marioLives > 0) { // while the Goomba is not defeated Mario still stays
                                    defeatedGoomba = mario.defeatGoomba(); // he fights the Goomba again
                                    marioLives = mario.getLives(); // his lives are checked again
                                    ++turn;
                                    // if Mario uses up all his lives, the game ends here...
                                }
                                if (defeatedGoomba) { // if Mario ends up defeating the Goomba
                                    cout << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                                    cout << "has " << marioCoins << " coins. ";
                                    outFile << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                                    outFile << "has " << marioCoins << " coins. ";
                                    world[marioLevel]->setNothing(row, col); // set this position to nothing
                                    dir = std::rand() % 4;
                                    nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                                    cout << "Mario will move " << nextDir << "." << endl;
                                    outFile << "Mario will move " << nextDir << "." << endl;
                                    ++turn;
                                }
                            }
                            else { // when his power level is greater than 1, mario simply moves on with the Goomba staying in position
                                marioLives = mario.getLives(); // his lives are checked again
                                cout << "lost. Mario has " << marioLives << " lives left. Mario" << endl;
                                cout << "has " << marioCoins << " coins. ";
                                outFile << "lost. Mario has " << marioLives << " lives left. Mario" << endl;
                                outFile << "has " << marioCoins << " coins. ";
                                dir = std::rand() % 4;
                                nextDir = world[marioLevel]->moveOn(dir);
                                cout << "Mario will move " << nextDir << "." << endl; 
                                outFile << "Mario will move " << nextDir << "." << endl;                                
                                ++turn;
                            }
                        }
                        break;
                    case 'k': // a koopa
                        cout << "encountered a koopa and ";
                        outFile << "encountered a koopa and ";
                        marioPowerLevel = mario.getPowerLevel(); // an int for Mario's power level
                        defeatedKoopa = mario.defeatKoopa(); // a bool for if Mario defeats him or not
                        marioLives = mario.getLives(); // check Mario's number of lives
                        if (defeatedKoopa) { // if the Koopa is defeated
                            cout << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                            cout << "has " << marioCoins << " coins. ";
                            outFile << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                            outFile << "has " << marioCoins << " coins. ";
                            world[marioLevel]->setNothing(row, col); // set this position to nothing
                            dir = std::rand() % 4;
                            nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                            cout << "Mario will move " << nextDir << "." << endl;
                            outFile << "Mario will move " << nextDir << "." << endl;
                            ++turn;
                        }
                        else { // if Mario lost
                            if (marioPowerLevel == 0) { // if Mario's power level is 0
                                while (!defeatedKoopa && marioLives > 0) { // while the Koopa is not defeated Mario still stays
                                    defeatedKoopa = mario.defeatKoopa(); // he fights the Koopa again
                                    marioLives = mario.getLives(); // his lives are checked again
                                    ++turn;
                                    // if Mario uses up all his lives, the game ends here...
                                }
                                if (defeatedKoopa) { // if Mario ends up defeating the Koopa
                                    cout << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                                    cout << "has " << marioCoins << " coins. ";
                                    outFile << "won. Mario has " << marioLives << " lives left. Mario" << endl;
                                    outFile << "has " << marioCoins << " coins. ";
                                    world[marioLevel]->setNothing(row, col); // set this position to nothing
                                    dir = std::rand() % 4;
                                    nextDir = world[marioLevel]->moveOn(dir); // Mario moves on to a new position
                                    cout << "Mario will move " << nextDir << "." << endl;
                                    outFile << "Mario will move " << nextDir << "." << endl;
                                    ++turn;
                                }
                            }
                            else { // when his power level is greater than 1, mario simply moves on with the Koopa staying in position
                                marioLives = mario.getLives(); // his lives are checked again
                                cout << "lost. Mario has " << marioLives << " lives left. Mario" << endl;
                                cout << "has " << marioCoins << " coins. ";
                                outFile << "lost. Mario has " << marioLives << " lives left. Mario" << endl;
                                outFile << "has " << marioCoins << " coins. ";
                                dir = std::rand() % 4;
                                nextDir = world[marioLevel]->moveOn(dir);
                                cout << "Mario will move " << nextDir << "." << endl;  
                                outFile << "Mario will move " << nextDir << "." << endl;                                
                                ++turn;
                            }
                        }
                        break;
                    case 'b': // a boss
                    // proceed with BOSS rules of combat
                        cout << "fought with the BOSS and ";
                        outFile << "fought with the BOSS and ";
                        marioPowerLevel = mario.getPowerLevel(); // an int for Mario's power level
                        defeatedBoss = mario.defeatBoss(); // a bool for if Mario defeats him or not
                        while (!defeatedBoss && marioLives > 0) { // while the Boss is not defeated Mario still stays
                            defeatedBoss = mario.defeatBoss(); // he fights the Boss again
                            marioLives = mario.getLives(); // his lives are checked again
                            ++turn;
                            // if Mario uses up all his lives, the game ends here...
                        }
                        if (defeatedBoss) { // if Mario ends up defeating the Boss
                            cout << "WON!!!!!! Mario has " << marioLives << " lives left. Mario" << endl;
                            cout << "has " << marioCoins << " coins. ";
                            outFile << "WON!!!!!! Mario has " << marioLives << " lives left. Mario" << endl;
                            outFile << "has " << marioCoins << " coins. ";
                            if (marioLevel == levels - 1) { // if Mario is in the last level
                                gameWin = true; // Mario wins the game
                                finishedGame = true; // the game is finished
                                // while loop breaks!!!
                            }
                            else { // if Mario is not in the last level
                                world[marioLevel]->setNothing(row, col); // set this position to nothing
                                ++marioLevel; // increment Mario's level so he moves on to the next one
                                cout << "Mario MOVES ON to LEVEl " << marioLevel << "!" << endl;
                                outFile << "Mario MOVES ON to LEVEl " << marioLevel << "!" << endl;
                                turn = 0; // his turns are reset to 0 so he could be set again
                            }
                        }
                        break;
                    case 'w': // a warp pipe
                        cout << "has encountered a WARP PIPE! Mario has " << marioLives << " lives left. Mario" << endl;
                        cout << "has " << marioCoins << " coins. ";
                        outFile << "has encountered a WARP PIPE! Mario has " << marioLives << " lives left. Mario" << endl;
                        outFile << "has " << marioCoins << " coins. ";
                        ++marioLevel;
                        cout << "Mario MOVES ON to LEVEl " << marioLevel << "!" << endl;
                        outFile << "Mario MOVES ON to LEVEl " << marioLevel << "!" << endl;
                        turn = 0; // his turns are reset to 0
                        break;
                    default: // precaution for safety
                        cout << "Unknown character encountered!" << endl; // print if any characters that should not be there are seen
                        break;
                }
                cout << "=========================================================================" << endl;
                outFile << "=========================================================================" << endl;
                marioPowerLevel = mario.getPowerLevel(); // Mario's power level is checked for cout
                marioLives = mario.getLives(); // check Mario's lives again
                // if he has 0 lives, the game ends!
            }
            // // FINAL RESULTS

            if (gameWin) { // if Mario wins, write so
                // the princess is saved and print a goodbye message
                cout << endl;
                cout << "WE WON THE GAME :)" << endl;
                cout << "The Princess is Saved!!!!" << endl;
                cout << endl;
                cout << "Last Position: (" << row << ", " << col << ")" << endl;
                cout << "Power Level: " << marioPowerLevel << endl;
                cout << "Coins: " << marioCoins << endl;
                cout << "Lives: " << marioLives << endl;
                cout << endl;
                cout << "Thank you for playing" << endl;
                outFile << endl;
                outFile << "WE WON THE GAME :)" << endl;
                outFile << "The Princess is Saved!!!!" << endl;
                outFile << endl;
                outFile << "MARIO DETAILS" << endl;
                outFile << "-------------" << endl;
                outFile << endl;
                outFile << "Last Position: (" << row << ", " << col << ")" << endl;
                outFile << "Power Level: " << marioPowerLevel << endl;
                outFile << "Coins: " << marioCoins << endl;
                outFile << "Lives: " << marioLives << endl;
                outFile << endl;
                outFile << "Thank you for playing" << endl;
            }
            else { // if he doesn't win, write so
                // print Mario's status where lives is 0
                cout << endl;
                cout << "WE LOST THE GAME! :(" << endl;
                cout << endl;
                cout << "MARIO DETAILS" << endl;
                cout << "-------------" << endl;
                cout << endl;
                cout << "Last Position: (" << row << ", " << col << ")" << endl;
                cout << "Power Level: " << marioPowerLevel << endl;
                cout << "Coins: " << marioCoins << endl;
                cout << "Lives: " << marioLives << endl;
                cout << endl;
                cout << "try again..." << endl;
                outFile << endl;
                outFile << "WE LOST THE GAME! :(" << endl;
                outFile << endl;
                outFile << "MARIO DETAILS" << endl;
                outFile << "-------------" << endl;
                outFile << endl;
                outFile << "Last Position: (" << row << ", " << col << ")" << endl;
                outFile << "Power Level: " << marioPowerLevel << endl;
                outFile << "Coins: " << marioCoins << endl;
                outFile << "Lives: " << marioLives << endl;
                outFile << endl;
                outFile << "try again..." << endl;
            }
            outFile.close(); // closes writing file
    }
    else {
        cout << "Error writing to file!" << endl;
    }
}

World::~World() { // default destructor
    for (int i = 0; i < levels; i++) {
        delete world[i]; // deletes each Level object in world
    }
    delete[] world; // deletes the array of Levels in world
}

# Not So Super Mario Bros.

- A game simulation inspired by Super Mario Bros. that processes world configuration data — including levels, coin distribution, and enemy placements — to model gameplay progression and generate a detailed log of Mario’s movements, interactions, and status throughout the simulation.

## Author Info

- Full Name: Ethan E. Lopez
- Chapman Email: etlopez@chapman.edu


## Source Files
- Main.cpp
- FileProcessor.cpp
- FileProcessor.h
- World.cpp
- World.h
- Level.cpp
- Level.h
- Mario.cpp
- Mario.h
- Spec.txt

## Errors
- Segmentation Fault (Known Issue)

Likely causes include:
1. Out-of-bounds array/vector access
2. Null pointer dereferencing
3. Improper memory handling when generating levels or accessing grid positions

## Instructions For Running
- To compile: g++ *.cpp -o mario.exe
- To run: ./mario Spec.txt Log.txt

Note:
- "Log.txt" may be replaced with any .txt file for game play output
- Likewise "Spec.txt" may be any .txt file read with numbers from lines 1-8

## Usage

The program simulates Mario's progression through a structured world of levels.

### How The Program Works
---

1. Read in configuration data from an input file
2. Create a world consisting of multiple levels
3. Populate each level with coins, enemies, and empty space
4. Simulate Mario's progression through each level, collecting coins and encountering enemies
4. Log all progression to an output file

#### Example Execution

- ./mario Spec.txt Log.txt

#### Example Output (Log.txt):

*   Level 1 Start
*   Mario moved right
*   Encountered Goomba, Mario defeated enemy
*   Collected coin, Coins: 5

*   Mario moved down
*   Encountered enemy, Mario lost a life

*   Level Complete

*   Level 2 Start
*   ...

*   Game Over

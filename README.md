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

#### Example Output (Log.txt – Conceptual):

Level 1 Start
- Mario moved right
- Encountered Goomba, Mario defeated enemy
- Collected coin, Coins: 5
- Mario moved down
- Encountered enemy, Mario lost a life

Level Complete

Level 2 Start
...

Game Over

## Input Format

The file named "Spec.txt" is used to specify the game world's structure and parameters.

### Expected Structure
---

Configuration values and levels are included in the file. 
- Values are usually included in the first 8 lines of the file.

#### Example Format

- 2   // number of levels
- 5   // grid size NxN
- 3   // number of lives
- 20  // probability of obtaining coins
- 20  // probability of enemies
- 20  // probability of power-ups
- 20  // probability of mushrooms
- 20  // probability of empty spaces

#### Rules

1. Configuration values are to be numeric.
2. Grid size is used to determine the dimensions for levels.
3. Probability values should sum to 1.0.
4. Space in the grid is assumed to be empty.
5. Random seed is used to generate random values.

## Implementation Details

#### Core Components

1. File Processing

- FileProcessor processes input values and initializes simulation parameters
- Validates structure and converts raw input into usable data

2. World Representation

World comprises of:
- A set of Level objects
- Global parameters, for example, total levels

3. Level Structure

- Each Level is represented as a grid of cells
- Each cell comprises
   - Coin
   - Enemy
   - Empty
   - etc.

Grid is randomly generated using probabilities

4. Mario Class

- Tracks Mario’s:
    - State
    - Current Position
    - Number of lives
    - Coin Count
    - Movement History

Also Processes Mario’s Interactions:
- Coin collection
- Fighting enemies
- Losing lives
- Completing levels

### Algorithm
---

1. Initialize World and Mario

For each level:
- Place Mario at the start
- Move Mario
    - Move direction could be deterministic or random
- If cell content is
   - Coin
      - Increment coin count
   - Enemy
      - Fight enemy
   - Empty
      - Do nothing
- Log action
- Repeat until

Level is complete.

Game Ends When:
- Mario defeats boss.
- Mario runs out of lives.

### Data Structures Used
---

1. Vectors/Arrays

- Levels and grid data

2. 2D Grid
- For each level
- Represents the world

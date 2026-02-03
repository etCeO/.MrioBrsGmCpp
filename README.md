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
- "Segmentation Fault"
- I have no idea where this is occurring or how to fix it, but the program runs just fine otherwise...

## Instructions For Running
- To compile: g++ *.cpp -o mario.exe
- To run: ./mario Spec.txt Log.txt
- Note: "Log.txt" may be replaced with any .txt file for game play output
- Likewise "Spec.txt" may be any .txt file read with numbers from lines 1-8

// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include "FileProcessor.h" // includes FileProcessor class
#include "World.h" // includes World class
#include "Level.h" // includes Level class
#include "Mario.h" // includes Mario class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

int main(int argc, char* argv[]) { // main method
// takes in a txt file and processes its contents
    std::srand(std::time(0)); // time seed for objects

    FileProcessor fp; // file processor object fp for reading

    cout << endl; // newline for neatness

    try { // try the following program
        cout << "NOT SO SUPER MARIO BROS." << endl;
        cout << endl; // newline for neatness
        int* worldArr = fp.readFiles(argv[1]); // readFiles() method returns an array of ints
        World wrld(worldArr, argv[2]); // this array of ints is used in World constructor to play the game
        delete[] worldArr; // deallocates worldArr
    }
    catch (const std::exception& e) { // if something goes wrong
        std::cerr << "Error loading file... " << e.what() << endl;
        // print an error occurred and communicate what happened
        return 1; // end the program
    }

    cout << endl; // newline for neatness

    return 0; // ends the program when success

}
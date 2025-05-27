// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA2: Not So Super Mario Bros.

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes if::stream and of::stream
#include <sstream> // includes string stream for numbers in txt
#include "FileProcessor.h" // includes contents from header file
#include "World.h" // includes World class
#include "Level.h" // includes Level class
#include "Mario.h" // includes Mario class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

// CONSTRUCTORS AND DESTRUCTORS

FileProcessor::FileProcessor(){};
// file processor requires a default constructor to assign new values

FileProcessor::~FileProcessor(){};

// PUBLIC METHOD

int* FileProcessor::readFiles(std::string inFileName) {
// a public void method that reads a txt file and plays the game with that information, outputting details in another txt file

    int* infoArr = new int[8]; // a dynamic array of 8 integers is declared
    std::ifstream inFile(inFileName); // txt method for file reading
    std::string line; // string line for each line's details
    int lineNum = 0; // keeps track of each line number
    int line1 = 0, line2 = 0, line3 = 0, line4 = 0, line5 = 0, line6 = 0, line7 = 0, line8 = 0;
    // assigned to default values until read from the txt

    if (inFile.is_open()) {
        // if reading opened successfully

        while (std::getline(inFile, line)) {
        // for each line in file

            std::stringstream ss(line);
            // create a stringstream for each line
            int lineInt;
            ss >> lineInt;
            // stringstream converts line into an int and stores it in variable lineInt

            switch (lineNum) {
            // in the case of each line
            // assign the value in its appropriate order
                case 0:
                    line1 = lineInt;
                    infoArr[0] = line1;
                    // first line goes to 0th element
                    break;
                case 1:
                    line2 = lineInt;
                    infoArr[1] = line2;
                    // second line goes to 1st element
                    break;
                case 2:
                    line3 = lineInt;
                    infoArr[2] = line3;
                    // third line goes to 2nd element
                    break;
                case 3:
                    line4 = lineInt;
                    infoArr[3] = line4;
                    // fourth line goes to 3rd element
                    break;
                case 4:
                    line5 = lineInt;
                    infoArr[4] = line5;
                    // fifth line goes to 4th element
                    break;
                case 5:
                    line6 = lineInt;
                    infoArr[5] = line6;
                    // sixth line goes to 5th element
                    break;
                case 6:
                    line7 = lineInt;
                    infoArr[6] = line7;
                    // seventh line goes to 6th element
                    break;
                case 7:
                    line8 = lineInt;
                    infoArr[7] = line8;
                    // eigth line goes to 7th element
                    break;
                default:
                // safety reasons in case a line is missed
                    cout << "Ignoring line " << lineNum + 1 << endl;
                    break;
            }
            ++lineNum;
            // increment lineNum during the while loop
        }

        if (line4 + line5 + line6 + line7 + line8 != 100) {
            // if lines 4-8 do not add to 100, these are invalid percentages
            // do not proceed with game play and instead print this error
            cout << "ERROR: lines 4 - 8 must add to 100!" << endl;
        }
        inFile.close(); // close reading

    }
    else { // if the inFile and outFile do not open properly
        cout << "Error: Something went wrong when reading the file!" << endl;
        // stop all operations and print the error
    }
    return infoArr; // returns the array of info
}

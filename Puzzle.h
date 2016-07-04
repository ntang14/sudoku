/*Nancy Tang 12/1/2015 Puzzle.h file
This file provides the class for a Puzzle object that holds a Sudoku puzzle.
The puzzle object holds 81 Square objects, with each Square representing a
square in the puzzle. The Puzzle object is created by reading in 81 valid
values from cin to create the puzzle. The Puzzle object also solves the Sudoku
puzzle by doing backtracking. The Puzzle object also handles whether or not a
certain value can go into a certain Square. The Puzzle must ensure that within
the same row, column, and block, there are no duplicate numbers.*/

#ifndef PUZZLE_H
#define PUZZLE_H

#include "Square.h"
#include <iostream>

class Puzzle {
   
   //takes in a puzzle from cin
   friend istream& operator>>(istream& input, Puzzle& thisPuzzle);
   
   // prints out a puzzle to cout.
   // prints out as a list of numbers
   friend ostream& operator<<(ostream& output, const Puzzle& thisPuzzle);

public:

   // default constructor
   Puzzle();
   
   // destructor
   ~Puzzle();
   
   // prints out a human-friendly version of the puzzle that is formatted
   // and easy to read
   void display();
   
   // solves the Sudoku puzzle using backtracking
   bool solve(int row, int column);
   
   // returns a const reference to the Square object at the given location
   // the location is indicated by the row and column ints that are passed in
   Square& get(int x, int y);

private:
   Square **grid;
   int puzzleSize;
   int stillEmpty;
   
   // sets the value of the Square object at the given co-ordinates with the
   // give value after testing to make sure placement of the value does not
   // violate the rules of Sudoku
   bool set(int x, int y, int value);
   
   // returns the size of the puzzle when it was created
   int size();
   
   // returns how many Squares left that are empty (do not have a value)
   int numEmpty();

};

#endif
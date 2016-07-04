/*Nancy Tang 12/1/2015 Square.h file
This file provides the class for a Square object in a Sudoku puzzle. Each
Square object holds an int value and flag for whether or not it is a fixed
value that was given at the creation of the puzzle. The Square object assumes
that the Puzzle will determine whether or not a value can be placed in a given
Square, so the function to set the value of the Square object is protected, but
has the Puzzle class as a friend.*/

#ifndef SQUARE_H
#define SQUARE_H
using namespace std;

class Square {

// allows the puzzle class to access the setValue function
friend class Puzzle;

public:

   // default constructor
   // takes an int and a bool for parameters
   // if no parameters are given, indicates an empty space in the puzzle
   Square(int = 0, bool = false);
   
   // returns the current value in the Square
   int getValue();
   
   //returns whether or not the value in the Square was set at the beginning
   bool isFixed();

private:
   bool fixed;
   int value;
   
protected:

   // sets the value to the int that is passed in
   // assumes that Puzzle class checked to see if the int passed in is valid
   bool setValue(int num);
};

#endif
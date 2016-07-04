/*Nancy Tang 12/1/2015 Square.cpp file
This file provides the functions for a Square class used in a Sudoku puzzle.
Each Square object holds an int value and flag for whether or not it is a fixed
value that was given at the creation of the puzzle. The Square object assumes
that the Puzzle will determine whether or not a value can be placed in a given
Square, so the function to set the value of the Square object is protected, but
has the Puzzle class as a friend*/

#include "Square.h"

// default constructor
// Pre-condition: an int named value with no value and a bool named fixed with
// no value
// Parameter: and int and a bool
// Post-condition: value is set to the int passed in and fixed is set to the
// bool passed in. If no parameters were passed in, value sets to 0 and fixed
// sets to false. This indicates an empty square.
Square::Square(int num, bool set) {
   value = num;
   fixed = set;
}

// getValue
// Pre-condition: value is set to some int
// Parameter: none
// Post-condition: function returns value
int Square::getValue() {
   return value;
}

// setValue
// Pre-condition: value is set to some int
// Parameter: an int
// Post-condition: value is set to the int passed in. Function returns whether
// or not setting the value was successful.
// Square object does not test whether or not setting the value to a certain
// int breaks the rules of the Sudoku puzzle.
bool Square::setValue(int num) {
   value = num;
   return true;
}


// isFixed
// Pre-condition: bool fixed is either true or false
// Parameter: none
// Post-condition: function returns whether or not fixed is true or false.
bool Square::isFixed() {
	return fixed;
}
/*Nancy Tang 12/1/2015 Puzzle.cpp file
This file provides the functions for a Puzzle class that holds a Sudoku puzzle.
The puzzle object holds 81 Square objects, with each Square representing a
square in the puzzle. The Puzzle object is created by reading in 81 valid
values from cin to create the puzzle. The Puzzle object also solves the Sudoku
puzzle by doing backtracking. The Puzzle object also handles whether or not a
certain value can go into a certain Square. The Puzzle must ensure that within
the same row, column, and block, there are no duplicate numbers.*/

#include "Puzzle.h"
#include "Square.h"

// default constructor
// Pre-condition: a pointer to a 2-D array that points to nothing, an int named
// puzzle size that has no value, and an int named stillEmpty that has no value
// Parameter: none
// Post-condition: a pointer that points to the head of a 2-D array that can
// hold 81 Square objects, puzzleSize is set to 0 and stillEmpty is set to 81
// because no Square values have been set yet.
Puzzle::Puzzle() {
   grid = new Square* [9];
   for (int i = 0; i < 9; i++) {
      grid[i] = new Square [9];
   }
   puzzleSize = 0;
   stillEmpty = 81;
}

// destructor
// Pre-condition: a 2-D array of Square objects
// Parameter: none
// Post-condition: each row and column has its values deleted and then each
// pointer is set to NULL
Puzzle::~Puzzle() {
   for (int i = 0; i < 9; i++) {
     delete [] grid[i];
     grid[i] = NULL; 
   }
   delete [] grid;
   grid = NULL;
}

// get
// Pre-condition: a Puzzle object that holds Square objects
// Parameter: two ints that indicate which row and column of the puzzle
// to grab the Square object
// Post-condition: returns a const reference to the Square object in the
// given place
Square& Puzzle::get(int x, int y) {
   return grid[x][y];
}

// set
// Pre-condition: a Square with no set value
// Parameter: x and y co-ordinates in the form of ints and an int that gives
// the value that the Square object needs to have.
// Post-condition: the Square object that is asked for has its value changed to
// the value passed in if it is valid and does not break the rules of Sudoku.
// The function tests to make sure that no other value in the same row, column,
// or block have the same value to allow the value to be set.
bool Puzzle::set(int x, int y, int value) {
   for (int i = 0; i < 9; i++) {
   
      //check the values in the same row
      if (get(x, i).getValue() == value) {
         return false;
      }
      
      //check the values in the same column
      if (get(i, y).getValue() == value) {
         return false;
      }
      
      //check the values in the same block
      if (get(x - (x % 3) + (i / 3), y - (y % 3) + (i % 3)).getValue()
            == value) {
         return false;
      }
   }
   get(x, y).setValue(value);
   return true;
}

// display
// Pre-condition: a Puzzle object that holds values
// Parameter: none
// Post-condition: a human-friendly version of the puzzle. The output is
// formatted to allow for easy understanding.
void Puzzle::display() {
   
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << get(i, j).getValue() << " ";
         if (j == 2 || j == 5) {
            cout << "|";
         }
      }
      cout << endl;
      if (i == 2 || i == 5) {
         cout << "------+------+-----" << endl;
      }
   }
   cout << endl;
}

// size
// Pre-condition: puzzleSize contains the size of the puzzle when it was built
// Parameter: none
// Post-condition: returns the size of the puzzle when it was built
int Puzzle::size() {
   return puzzleSize;
}

// numEmpty
// Pre-condition: stillEmpty contains the number of Square objects that do not
// yet have a value.
// Parameter: none
// Post-condition: returns the number of Squares still empty in the Puzzle.
int Puzzle::numEmpty() {
   return stillEmpty;
}

// solve
// Pre-condition: a set Puzzle that has not been solved.
// Parameter: two ints that give the starting point for the function to start
// looking at possible empty Squares that need to be filled.
// Post-condition: a solved Puzzle that does not break any of the rules of
// Sudoku.
bool Puzzle::solve(int row, int column) {
   // done with Puzzle when all Squares are filled
   if (stillEmpty == 0) {
      return true;
   }
   
   // brings column back if it walks off the edge
   if (column == 9) {
      row++;
      column = 0;
   }
   
   // looks for next square that does not have a fixed value
   for(;;) {
      if(!get(row, column).isFixed()) {
         break;
      } else {
         column++;
         if (column == 9) {
            row++;
            column = 0;
         }
      }
   }
   
   // tries values 1 through 9 for the given Square and moves on to the next
   // position when it finds one that works.
   for (int i = 1; i <= 9; i++) {
      if (set(row, column, i)) {
         stillEmpty--;
         if (solve(row, column + 1)) {
            return true;
         }
         // if rest of the puzzle cannot be solved, undo and try again
         get(row, column).setValue(0);
         stillEmpty++;
      }
   }
   return false;
}

// overloaded<< operator
// Pre-condition: a set Puzzle
// Parameter: the ostream and the puzzle that needs to be outputted
// Post-condition: outputs a puzzle in a single line
ostream& operator<<(ostream& output, Puzzle& thisPuzzle) {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         output << thisPuzzle.get(i, j).getValue();
      }
   }
   return output;
}

// overloaded>> operator
// Pre-condition: an initialized Puzzle where the Square objects within do not
// yet have a value.
// Parameter: istream and the puzzle that needs to be made using cin.
// Post-condition: a set Puzzle object that was created by reading values from cin.
istream& operator>>(istream& input, Puzzle& thisPuzzle) {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         for(;;) {
            char temp;
            input >> temp;
            int value = (int) temp;
            if (value > 47 && value < 58) {
               if (value == 48) {
                  thisPuzzle.get(i, j) = Square();
               } else {
                  thisPuzzle.get(i, j) = Square (value - 48, true);
                  thisPuzzle.puzzleSize += 1;
                  thisPuzzle.stillEmpty -= 1;
               }
               break;
            }
         }
      }
   }
   return input;
}
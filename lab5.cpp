/*Nancy Tang 12/1/2015 lab5.cpp file
The following program takes Sudoku puzzles and solves them. The program takes
in values from cin to create the puzzle. If there are invalid things sent in
through cin the program ignores them and waits until exactly 81 valid values
are taken in. After the Puzzle is created the driver solves them and then
displays them in a human-friendly view. The program assumes that the puzzles
that are sent in do not already break the rules of Sudoku.*/

#include <iostream>
using namespace std;

#include "Puzzle.h"
#include "Square.h"

// creates a Puzzle, reads in values from cin to fill it, displays the initial
// Puzzle, solves the Puzzle, and displays the completed Puzzle if it was
// successful. Otherwise it prints a statement saying that the puzzle could not
// be solved.
int main() {
   Puzzle p;
   
   cin >> p;
   p.display();
   
   if (p.solve(0, 0)) {
      p.display();
   } else {
      cout << "This Sudoku puzzle could not be solved." << endl;
   }
   return 0;
}
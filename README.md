# sudoku
This project solves sudoku puzzles using recursion

The program takes in 81 valid values from cin to create the puzzle. If invalid inputs are put in, the program ignores them and continues to wait until there are 81 valid values. Valid values are ints from 0-9. 0's represent blank spaces in the puzzle. The program assumes that the puzzle that is inputted does not already break the rules of sudoku.

The proram creates a Puzzle object to solve the problem. The Puzzle object creates a 9x9 2-d array of Square objects that each keep track of what number is currently in that square (if any) and whether or not that number is fixed. The Puzzle object uses backtracking recursion to place numbers in the 2-d array until either the array is filled or until there are no possibilities to move forward. If the array is full, the Puzzle object prints a human-friendly version of the solved puzzle. If there were no possibilities to move forward, the program prints a line telling the user that a solution could not be found.

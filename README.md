# Sudoku_Solver

Sudoku Solver designed to solve Sudoku puzzles using Backtracking Algorithm. Sudoku is a popular logic-based number placement puzzle game that involves a 9x9 grid divided into nine 3x3 subgrids or "regions." The goal of Sudoku is to fill in the grid with numbers from 1 to 9 in such a way that each row, each column, and each of the nine 3x3 regions contains all of the digits from 1 to 9 without any repetition.


Two options to select for input:
1. manually input the puzzle.
2. generate the puzzle.

# How to generate Sudoku Puzzle
1. Fill all the diagonal 3x3 matrices.
2. Fill recursively the rest of the non-diagonal matrices. For every cell to be filled, we try all numbers until we find a safe number to be placed.  
3. Once the matrix is fully filled, remove K elements randomly to complete game

# How to Solve Sudoku.
Sudoku Solver using Backtracking Algorithm
1. Create a function that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.
2. Create a recursive function that takes a grid.
3. Check for any unassigned location. 
4. If present then assigns a number from 1 to 9.
5. Check if assigning the number to the current index makes the grid unsafe or not. 
6. If safe then recursively call the function for all safe cases from 0 to 9.
7. If any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.
8. If there is no unassigned location then return true.

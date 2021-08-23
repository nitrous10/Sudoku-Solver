/**
 * solver.c - contains functions that help solve sudoku puzzles and determine uniqueness
 * 
 * CS50, Summer 2021
 * Author: Noah Yusen
 */

#include <stdlib.h>
#include <stdbool.h>
#include "solver.h"
#include "../common/sudokulib.h"

typedef struct puzzle {
    int array[size][size];
} puzzle_t;

/**
 * puzzle_solve_forwards - a function to solve sudoku puzzles using backtracking
 * Inserts lower numbers into unassigned boxes first
 * params:
 *  puzzle - the sudoku puzzle to solve
 */
bool puzzle_solve_forwards(puzzle_t *puzzle) {
    int row = -1;
    int col = -1;
    find_next_unassigned(puzzle, &row, &col); // Get next unassigned box
    if (row == -1 && col == -1) { // Puzzle is solved (no 0's)
        return true;
    } else {
        for (int i = 1; i < 10; i++) { // Loop through each possible number
            if (isValidInput(puzzle, row, col, i)) { // Check to see whether the number can be inserted here
                puzzle_insert(puzzle, row, col, i);
                if (puzzle_solve_forwards(puzzle)) { // Attempt to solve the puzzle assuming this number is correct
                     return true;
                }
            }
        }
    }

    // No solution for the given puzzle, so reset this coordinate
    cell_delete(puzzle, row, col);
    return false;
}

/**
 * puzzle_solve_backwards - a function to solve sudoku puzzles using backtracking
 * Inserts higher numbers into unassigned boxes first
 * params:
 *  puzzle - the sudoku puzzle to solve
 */
bool puzzle_solve_backwards(puzzle_t *puzzle) { // See puzzle_solve_forwards for algorithmic flow
    int row = -1;
    int col = -1;
    find_next_unassigned(puzzle, &row, &col);
    if (row == -1 && col == -1) {
        return true;
    } else {
        for (int i = 9; i > 0; i--) {
            if (isValidInput(puzzle, row, col, i)) {
                puzzle_insert(puzzle, row, col, i);
                if (puzzle_solve_backwards(puzzle)) {
                     return true;
                }
            }
        }
    }
    cell_delete(puzzle, row, col);
    return false;
}

/**
 * find_next_unassigned - finds the next empty cell in a sudoku puzzle
 * params:
 *  puzzle - the sudoku puzzle to parse
 *  row - the pointer to the integer that will hold the row of the first unassigned box
 *  col - the pointer to the integer that will hold the column of the first unassigned box 
 */
void find_next_unassigned(puzzle_t *puzzle, int *row, int *col) {
    for (int i = 0; i <= 8; i++) { // Loop through each row
        for (int j = 0; j <= 8; j++) { // Loop through each column
            if (puzzle_lookup(puzzle, i, j) == 0) { // Check if the number at the current coordinate equals 0 (empty)
                *col = j;
                *row = i;
                return;
            }
        }
    }
}

/**
 * check_unique - determines whether a puzzle has a unique solution
 * Solves the puzzle forward and backwards and checks if the two solutions are equal
 * params:
 *  puzzle - the sudoku puzzle to solve
 */
bool check_unique(puzzle_t *puzzle) {
    puzzle_t *puzzleCopy1 = puzzle_copy(puzzle); // Copy so we don't solve original puzzle
    if (puzzle_solve_forwards(puzzleCopy1)) { // Puzzle has a solution

        // Solve the same puzzle backwards
        puzzle_t *puzzleCopy2 = puzzle_copy(puzzle);
        puzzle_solve_backwards(puzzleCopy2);

        bool result = compare_puzzles(puzzleCopy1, puzzleCopy2); // Determine if forwards and backwards yields same solution
        
        // Clean up memory
        puzzle_delete(puzzleCopy1);
        puzzle_delete(puzzleCopy2);

        return result;
    } else { // Puzzle did not have a solution
        puzzle_delete(puzzleCopy1);
        return false;
    }
}

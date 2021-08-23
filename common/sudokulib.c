/*
 * sudokulib.c - helper functions for sudoku modules
 *
 * Written in collaboration by Melissa Valencia, Noah Yusen, 
 * Clay Papanek, and Emily Zhou
 * 
 * See sudokulib.h for more information
 * 
 * CS50 Summer 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define size 9

typedef struct puzzle {
    int array[size][size];
} puzzle_t;

/**
 * puzzle_new - Creates a new sudoku puzzle and initializes each cell to 0
 */
puzzle_t *puzzle_new() {
    puzzle_t *puzzle = malloc(sizeof(puzzle_t));

    if (puzzle == NULL) {
        return NULL;
    } else {
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                puzzle->array[i][j] = 0;
            }
        }
    }
    return puzzle;
}

/**
 * puzzle_copy - Creates a new sudoku puzzle that is a copy of a given sudoku puzzle
 * params:
 *  puzzle - the sudoku puzzle to copy
 */
puzzle_t *puzzle_copy(puzzle_t *puzzle) {
    if (puzzle == NULL) {
        return NULL;
    }
    puzzle_t *copy = puzzle_new();
    if (copy == NULL) {
        return NULL;
    }
    for (int i = 8; i >= 0; i--) {
        for (int j = 8; j >= 0; j--) {
            copy->array[i][j] = puzzle->array[i][j];
        }
    }
    return copy;
}

/**
 * puzzle_lookup - Returns the number located at the specified coordinate in the specified puzzle
 * params:
 *  puzzle - the puzzle in which to look
 *  row - the row of the cell
 *  col - the column of the cell
 */
int puzzle_lookup(puzzle_t *puzzle, int row, int col) {
    if (row < 0 || col < 0 || row >= 9 || col >= 9) {
        fprintf(stderr, "Invalid row/column\n");
        return -1;
    } else if (puzzle == NULL) {
        fprintf(stderr, "Invalid puzzle (null)\n");
        return -1;
    }
    return puzzle->array[row][col];
}

/**
 * puzzle_delete - Cleans up the memory used by a sudoku puzzle
 * params:
 *  puzzle - the sudoku puzzle to delete
 */
void puzzle_delete(puzzle_t *puzzle) {
    if (puzzle != NULL) {
        free(puzzle);
    }
}

/**
 * cell_delete - Empties a cell within a sudoku puzzle by initializing its value to 0
 * params:
 *  puzzle - the sudoku puzzle in which to delete a cell
 *  row - the row of the cell to delete
 *  col - the column of the cell to delete
 */
void cell_delete(puzzle_t *puzzle, int row, int col) {
    if (puzzle != NULL) {
        puzzle->array[row][col] = 0;
    }
}

/**
 * puzzle_insert - Inserts a number into the specified cell of a sudoku puzzle
 * params:
 *  puzzle - the sudoku puzzle in which to insert
 *  row - the row of the cell to insert into
 *  col - the column of the cell to insert into
 *  insertNum - the number to insert
 */
void puzzle_insert(puzzle_t *puzzle, int row, int col, int insertNum) {
    if (puzzle != NULL) {
        puzzle->array[row][col] = insertNum;
    }
}

/**
 * puzzle_print - Prints a text representation of a sudoku puzzle
 * params:
 *  puzzle - the sudoku puzzle to print
 *  fp - the file to which the puzzle will be printed
 */
void puzzle_print(puzzle_t *puzzle, FILE *fp) {
  if (puzzle == NULL || fp == NULL) return;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      fprintf(fp, "%d ", puzzle->array[i][j]);
    }
    fprintf(fp, "\n");
  }
}

/**
 * puzzle_load - Converts a text representation of a sudoku puzzle into a puzzle in memory
 * params:
 *  fp - the file from which to read the sudoku puzzle
 */
puzzle_t *puzzle_load(FILE *fp) {
    if (fp == NULL){
        return NULL;
    }
    puzzle_t *puzzle = puzzle_new();
    if (puzzle == NULL) {
        return NULL;
    }
    int row = 0;
    int col = 0;
    int temp = 0;
    while(fscanf(fp, "%d ", &temp) == 1) {
        puzzle->array[row][col] = temp;
        col++;
        if (col == 9) {
            col = 0;
            row++;
        }
        if (row == 9) {
            break;
        }
    }
    return puzzle;
}

/**
 * compare_puzzles - Determines whether two sudoku puzzles are equivalent
 * params:
 *  p1 - The first sudoku puzzle to compare
 *  p2 - The second sudoku puzzle to compare
 */
bool compare_puzzles(puzzle_t *p1, puzzle_t *p2) {
    if (p1 == NULL || p2 == NULL) {
        return false;
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            if (p1->array[i][j] != p2->array[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * isValidInput - Checks whether a number can be placed into a specific cell in a given puzzle
 * Checks if the number is valid in the given row, column, and 3x3 grid
 */
bool isValidInput(puzzle_t *puzzle, int row, int col, int insertNum) {
    // Check row
    for (int i = 0; i <= 8; i++) {
        if (puzzle->array[row][i] == insertNum) {
            return false;
        }
    }

    // Check col
    for (int i = 0; i <= 8; i++) {
        if (puzzle->array[i][col] == insertNum) {
            return false;
        }
    }

    // Check 3x3
    int smallRow = (row/3)* 3;
    int smallCol = (col/3) * 3;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (puzzle->array[smallRow + i][smallCol + j] == insertNum) {
                return false;
            }
        }
    }
    return true;
}
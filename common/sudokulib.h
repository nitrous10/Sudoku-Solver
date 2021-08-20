/* 
 * sudokulib.h - header file for CS50 sudoku module
 *
 * Written in collaboration by Melissa Valencia, Noah Yusen, 
 * Clay Papanek, and Emily Zhou
 *
 * CS50 Summer 2021
 */


#ifndef __PUZZLE_H
#define __PUZZLE_H
#define size 9

#include <stdio.h>
#include <stdbool.h>

/**************** global types ****************/
typedef struct puzzle puzzle_t;  // opaque to users of the module

/**************** functions ****************/

/**************** puzzle_new ****************/
/* Creates a new sudoku puzzle and initializes each cell 
 * to 0 to start.
 * 
 * 
 */
puzzle_t *puzzle_new();

/**************** puzzle_delete ****************/
/* Frees memory of the puzzle
 * 
 * 
 * 
 */
void puzzle_delete(puzzle_t *puzzle);

/**************** cell_delete ****************/
/* initializes cell to 0 
 * 
 * 
 * 
 */
void cell_delete(puzzle_t *puzzle, int row, int col);

/**************** puzzle_insert ****************/
/* inserts number to specific cell in sudoku puzzle
 * 
 * 
 * 
 */
void puzzle_insert(puzzle_t *puzzle, int row, int col, int insertNum);

/**************** puzzle_print ****************/
/* prints puzzle 
 * 
 * 
 * 
 */
void puzzle_print(puzzle_t *puzzle, FILE *fp);

/**************** puzzle_load ****************/
/* loads puzzle from file 
 * 
 * 
 * 
 */
puzzle_t *puzzle_load(FILE *fp);

/**************** compare_puzzles ****************/
/* compares two sudoku puzzles 
 * 
 * 
 * 
 */
bool compare_puzzles(puzzle_t *p1, puzzle_t *p2);

/**************** isValidInput ****************/
/* checks if placing a value in a cell is a valid placement
 * 
 * 
 * 
 */
bool isValidInput(int array[size][size], int row, int col, int insertNum);

#endif // __PUZZLE_H
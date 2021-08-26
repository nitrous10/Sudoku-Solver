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

/**************** puzzle_copy ****************/
/* Copies each value of an existing puzzle into a new puzzle
 * 
 * 
 * 
 */
puzzle_t *puzzle_copy(puzzle_t *puzzle);

/**************** puzzle_lookup ****************/
/* Returns the number in the specified row and column for the specified puzzle
 * 
 * 
 * 
 */
int puzzle_lookup(puzzle_t *puzzle, int row, int col);

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
bool isValidInput(puzzle_t *puzzle, int row, int col, int insertNum);

/**************** validPuzzle ****************/
/* checks if a given puzzle is valid in its current state
 * 
 * 
 * 
 */
bool validPuzzle(puzzle_t *puzzle);

#endif // __PUZZLE_H
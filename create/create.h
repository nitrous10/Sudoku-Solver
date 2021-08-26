/**
 * create.h - contains function headers for create.c
 * 
 * CS50, Summer 2021
 * Authors: Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen
 */


#include <stdlib.h>
#include <stdbool.h>
#include "../common/sudokulib.h"
#include "../solver/solver.h"


/**************** create ****************/
/* create() - Function to generate a valid puzzle  
 * calls puzzle_new to make the board
 * calls puzzle_solve_random to determine if the puzzle is solvable
 * chooses a random number between 40 and 63 that will be the number of empty cells in the puzzle
 * deletes that number of cells using cell_delete
 * checks thats the puzzle still has a unique solution using check_unique
 * if there are no more cells to delete, checked using all_cells_tried, and the number of cells removed is greater than or equal to 40 then return the puzzle
 * if there are no more cells to delete, but the number of cells removed is less than 40, call create again
 */
puzzle_t* create();

/**************** all_cells_tried ****************/
/* checks if there are no cells to remove that preserve a unique solution
 * the array we pass will have a zero in the position corresponding to every cell we have not checked
 * Thus, if any cell has a zero, we have not yet tried it, and our function returns false
 * Otherwise, return true
 */
bool all_cells_tried(int array[9][9]);

/**************** clear_array ****************/
/* go through the array storing what cells we have tried to remove, 
 * and reset every cell to 0, (essentially saying we have not yet tried to remove any cells
 * 
 */
void clear_array (int array[9][9]);

/**************** num_empty_cells ****************/
/* returns the number of blank cells in a puzzle
 * 
 */
int num_empty_cells(puzzle_t *puzzle);




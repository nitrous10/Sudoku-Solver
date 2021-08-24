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


puzzle_t* create();
bool all_cells_tried(int array[9][9]);
void clear_array (int array[9][9]);
int num_empty_cells(puzzle_t *puzzle);



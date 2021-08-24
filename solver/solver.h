/**************** functions ****************/

/**************** puzzle_solve_forwards ****************/
/* Tries to solve a sudoku puzzle using backtracking, assigning lower numbers
 * to unassigned boxes first
 * 
 * 
 */
bool puzzle_solve_forwards(puzzle_t *puzzle);

/**************** puzzle_solve_backwards ****************/
/* Tries to solve a sudoku puzzle using backtracking, assigning higher numbers
 * to unassigned boxes first
 * 
 * 
 */
bool puzzle_solve_backwards(puzzle_t *puzzle);

/**
 * puzzle_solve_random - a function to solve sudoku puzzles using backtracking
 * Inserts random numbers into unassigned boxes
 * params:
 *  puzzle - the sudoku puzzle to solve
 */
bool puzzle_solve_random(puzzle_t *puzzle);


/** Helper for puzzle_solve_random, 
 *  ensures the solve stays random
 */
bool seen_all_values (int valuesSeen[9]);


/**************** find_next_unassigned ****************/
/* Finds the next coordinate that does not currently contain a number (value is 0)
 * The values of the row and column pointers are updated to reflect this coordinate
 * 
 * 
 */
void find_next_unassigned(puzzle_t *puzzle, int *row, int *col);

/**************** check_unique ****************/
/* Checks whether a given sudoku puzzle contains a unique solution by
 * solving the puzzle forwards and backwards and comparing if they are equivalent
 * 
 * 
 */
bool check_unique(puzzle_t *puzzle);



// function headers for create operations
puzzle_t* create();
bool all_cells_tried(int array[9][9]);
void clear_array (int array[9][9]);
int num_empty_cells(puzzle_t *puzzle);



# Sudoku Implementation Spec
## Final Project, CS50, Summer 2021

### Sudoku
Sudoku is a puzzle consisting of a 9x9 grid of cells containing numbers between 1 and 9. These numbers are placed in certain cells determined by the rules of Sudoku. They must satisfy these rules: the number must appear only once in every row, only once in every column, and only once in every 3x3 squared region. The puzzle is first presented as a valid 9x9 grid with atleast 40 missing numbers, that is 40 empty cells. This puzzle that is created by the creator module must have a unique solution as well. To solve the puzzle, the program must satisfy the rules explained above, however the solver module is able to take puzzles with multiple solutions, but only returns one valid solutions. 

### Major data structures

Three helper modules provide data structures and functions:
 1. *common* which will declare data structures to represent the sudoku puzzle and will have functions relevant to creating, editing, printing, and checking sudoku puzzles
 2. *create* which randomly generates a randomized puzzle with at least 40 missing numbers
 3. *solve* which generates one solution for the puzzle without changing any numbers
 

### Usage

The *sudoku* program implemented in `sudoku.c`, implements data structures and modules: create, and solver, and uses utility functions and a data structure from the common library.
- sudoku.c simply calls functions from the create and solver modules
- create.c exports the following functions
```c
/**************** create ****************/
/* calls puzzle_new to make the board
 * calls puzzle_solve_random to determine if the puzzle is solvable
 * chooses a random number between 40 and 63 that will be the number of empty cells in the puzzle
 * deletes that number of cells using cell_delete
 * checks thats the puzzle still has a unique solution using check_unique
 * if there are no more cells to delete, that is check using all_cells_tried and the number of cells removed is greater than or equal to 40 then return the puzzle
 * if there are no more cells to delete, but the number of cells removed is less than 40, call create again
 * 
 */
puzzle_t* create();

/**************** all_cells_tried ****************/
/* checks whether there are any more empty cells 
 * if there is an empty cell, that is its value is 0, return false
 * if there are no more empty cells, return true
 * 
 */
bool all_cells_tried(int array[9][9]);

/**************** clear_array ****************/
/* go through the puzzle and set every cell to 0
 * 
 */
void clear_array (int array[9][9]);

/**************** num_empty_cells ****************/
/* returns the number of empty cells in a puzzle
 * 
 */
int num_empty_cells(puzzle_t *puzzle);

```
- solver.c exports the following functions:

```c
/**************** puzzle_solve_forwards ****************/
/* caller provides: puzzle
 * we return: true or false based on whether puzzle is solvable or not
 * 
 * find the empty cells
 * try to insert lower numbers into these cells first using backtracing
 * if there is not a solution with a given number, reset the coordinate
 * 
 */
bool puzzle_solve_forwards(puzzle_t *puzzle);
```

```c
/**************** puzzle_solve_backwards ****************/
/* caller provides: puzzle
 * we return: true or false based on whether puzzle is solvable or not
 * 
 * find the empty cells
 * try to insert higher numbers into these cells first using backtracing
 * if there is not a solution with a given number, reset the coordinate
 * 
 */
bool puzzle_solve_backwards(puzzle_t *puzzle);
```

```c
/**************** puzzle_solve_random ****************/
/* caller provides: a solvable puzzle
 * we return: true or false based on whether the puzzle is solvable or not
 * 
 * find the empty cells
 * try to insert numbers randomly into empty cells
 * if there is not a solution with a given number, reset the coordinate
 * Note: only works when called on a solvable puzzle
 * 
 */
bool puzzle_solve_random(puzzle_t *puzzle);
```

```c
/**************** seen_all_values ****************/
/* caller provides: an array of values between 1-9
 * return: true or false based on whether all the values in the array have been seen
 * 
 * helps ensure that the numbers chosen for solving the puzzle stay random and are not repetitive
 * 
 */
bool seen_all_values (int valuesSeen[9]);
```

```c
/**************** find_next_unassigned ****************/
/* caller provides: puzzle, int row, and int column
 * 
 * go through each row and each column
 * use puzzle_lookup to check if the cell is empty, that is the number at the current coordinate is 0
 * if it is empty, reset the column and row to equal the column and row where this cell is located
 * 
 */
void find_next_unassigned(puzzle_t *puzzle, int *row, int *col);
```

```c
/**************** check_unique ****************/
/* caller provides: a puzzle
 * we return: true or false based on whether the given puzzle has a unique solution or not
 * 
 * use puzzle_solve_forwards to solve the puzzle forward
 * use puzzle_solve_backwrds to solve the puzzle backward
 * compare the two puzzle solutions and if they are the same, then the solution is unique

 * 
 */
bool check_unique(puzzle_t *puzzle);
```

- sudokulib.c exports the following functions:
```c
/**************** global types ****************/
typedef struct puzzle puzzle_t;  // opaque to users of the module

/**************** functions ****************/

/**************** puzzle_new ****************/
/* we return: a puzzle
 * 
 * creates a new sudoku puzzle by initializing each cell 
 to 0 to start
 *
 */
puzzle_t *puzzle_new();

/**************** puzzle_copy ****************/
/* caller provides: a puzzle
 * we return: a copy of the given puzzle
 * 
 * creates a new sudoku puzzle that is a copy of the given puzzle
 * 
 */
puzzle_t *puzzle_copy(puzzle_t *puzzle);

/**************** puzzle_lookup ****************/
/* caller provides: a puzzle, row, and column
 * we return: the number at the specified coordinate in the puzzle
 * 
 */
int puzzle_lookup(puzzle_t *puzzle, int row, int col);

/**************** puzzle_delete ****************/
/* caller provides: a puzzle
 * 
 * cleans up the memory used by the sudoku puzzle
 * 
 */
void puzzle_delete(puzzle_t *puzzle);

/**************** cell_delete ****************/
/* caller provides: a puzzle, row, and column
 * params:
 * puzzle - the sudoku puzzle in which to delete a cell
 * row - the row of the cell to delete
 * col - the column of the cell to delete
 *
 * empties the specified cell with a puzzle by setting its value to 0
 * 
 */
void cell_delete(puzzle_t *puzzle, int row, int col);

/**************** puzzle_insert ****************/
/* caller provides: a puzzle, row, column, and number
 * params:
 * puzzle - the sudoku puzzle in which to insert
 * row - the row of the cell to insert into
 * col - the column of the cell to insert into
 * insertNum - the number to insert
 * 
 * inserts a number to specific cell in sudoku puzzle
 * 
 */
void puzzle_insert(puzzle_t *puzzle, int row, int col, int insertNum);

/**************** puzzle_print ****************/
/* caller provides: a puzzle, a file to print the puzzle to
 * params:
 *  puzzle - the sudoku puzzle to print
 *  fp - the file to which the puzzle will be printed
 * 
 * prints a text representation of a sudoku puzzle
 *
 */
void puzzle_print(puzzle_t *puzzle, FILE *fp);

/**************** puzzle_load ****************/
/* caller prpvides: a file to load the puzzle from
 * we return: a valid puzzle
 * params:
 *  fp - the file from which to read the sudoku puzzle
 * 
 * load a puzzle from a file
 * check this puzzles validity, using validPuzzle, that is it satisfies the sudoku rules
 * 
 */
puzzle_t *puzzle_load(FILE *fp);

/**************** compare_puzzles ****************/
/* caller provides: 2 puzzles to compare
 * we return: true if the puzzles are the same, false if they are different
 * params:
 *  p1 - The first sudoku puzzle to compare
 *  p2 - The second sudoku puzzle to compare
 * 
 * check the values at each cell in each puzzle and compare them
 *
 */
bool compare_puzzles(puzzle_t *p1, puzzle_t *p2);

/**************** isValidInput ****************/
/* caller provides: a puzzle, a row, a column, and a number
 * we return: true if the number is a valid insertion, false if it is an invalid insertion
 * 
 * checks if placing a value in a cell is a valid placement by satisfying the sudoku rules
 * the rules are that the number can only appear once in every row, once in every column, and once in every 3x3 squared region
 * 
 */
bool isValidInput(puzzle_t *puzzle, int row, int col, int insertNum);

/**************** validPuzzle ****************/
/* caller provides: a puzzle
 * we return: true, if it is valid, false, if it is not valid
 * 
 * checks if a given puzzle is valid in its current state
 * 
 */
bool validPuzzle(puzzle_t *puzzle);
```
### Data Flow

We implement this Sudoku program using the creator and solver modules, along with functions and a data structure from our common library, specifically, sudokulib.c.

We first check that the given arguments are valid, that is the program `./sudoku` and either `create` or `solve` are passed in. 

If the argument passed in is `./sudoku create` then we call our *create* function from create.c. This function will create a puzzle using *puzzle_new*. It will then call *puzzle_solve_random* to determine if the puzzle is solvable. Then, we generate a random number between 40 and 63 using *rand* which will be the number of empty cells in the sudoku puzzle. It then deletes that number of cells, that is by setting their value to zero and check that the puzzle still has a unique solution using *check_unique*. It will then check that there no more cells to delete by using *all_cells_tried* to look for cells with the value of 0. If there are no more cells to delete and there have already been 40 or more cells deleted, we return the puzzle. However, if there are less than 40 cells deleted, we call *create* again.

If the argument passed in is `./sudoku solve` then we call *puzzle_solve_forwards* to solve the puzzle by inserting lower numbers into the empty cells first and returning whether the puzzle is solvable or not. *puzzle_solve_forwards* finds every empty cell in the puzzle using *find_next_unassigned*. It then goes through each possible number to be inserted, that is numbers 1 through 9 and checks whether the number is a valid input using *isValidInput*. *isValidInput* will check if the number satisfies the Sudoku rules, that is the number only appearing once in the row, once in the column, and once in the 3x3 squared region. If the number is a vaild input, then we insert the number into the specified cell in the puzzle, using *puzzle_insert*. We then call *puzzle_solve_forwards* recursively to solve the whole puzzle.

### Assumptions

No assumptions beyond those that are clear from the spec.

### Files

* `Makefile` - compilation procedure
* `sudoku.c` - the implementation calling our create and solver modules
* `create.c` - functions for our creator module, creating a sudoku puzzle with atleast 40 empty cells and a unique solution
* `solver.c` - functions for our solver module, solving the Sudoku puzzle while satisfying the Sudoku rules
* `sudokulib.c` - functions for our puzzle data structure and helper functions
* `fuzztesting.sh` - fuzz testing for our Sudoku program testing both the creator and solver modules

### Compilation

To compile, simply `make`.

### Testing

The `testing.sh` program tests some created puzzles and solves them.
It tests a few error and edge cases.
This test is somewhat minimal.
A lot more could be done!

To test, simply `make test`.

To test with valgrind, `make valgrind`.
# Sudoku Design Spec
## Final Project, CS50, Summer 2021

The **sudoku** program is composed of two modules: a creator and a solver. The creator creates a random Sudoku puzzle, while the solver solves a given Sudoku puzzle. The **sudoku creator** must create a puzzle that has a unique solution. The puzzle created will have at least 40 missing numbers, be randomized, and then printed to `stdout`. The **sudoku solver** will be able to accept puzzles that have multiple solutions, and generate any one possible solution for the given puzzle. The solver must not change any given numbers in the puzzle. It should read the puzzle from `stdin` and print the solution to `stdout`.

A Design Spec should contain several sections:

* User interface
* Inputs and Outputs
* Functional decomposition into modules
* Pseudo code for logic/algorithmic flow
* Dataflow through modules
* Major data structures
* Testing plan

Let's look through each.

### User interface
The sudoku's only interface with the user is on the command-line; it musy always have one argument.

Two parts to the user interface:

Create:

```bash
./sudoku create
```

Solve:

```bash
./sudoku solve
```


### Inputs and Outputs

Input: the inputed command-line parameter determines whether or not a sudoku puzzle will be created or solved

Output: 9 lines of text that represent a solvable sudoku puzzle. If the command is `create`, the output is an random unsolved puzzle with a unique solution. If the command is `solve`, the output is a solved puzzle (the puzzle to solve is specified by the user).

For example:

`./sudoku create` will output
```bash
Created Puzzle:
0 7 0 6 0 0 0 4 0 
0 0 0 0 2 0 8 0 5 
0 3 0 0 0 8 0 0 0 
0 0 0 0 0 0 3 0 0 
4 1 0 0 0 0 0 0 0 
2 0 0 7 8 0 0 0 9 
0 0 8 0 5 0 0 7 6 
0 0 0 2 0 0 0 3 0 
1 5 0 0 0 0 0 0 0 
```

`./sudoku solve` will output
```bash
Solved Puzzle:
8 7 2 6 1 5 9 4 3 
9 4 1 3 2 7 8 6 5 
5 3 6 9 4 8 7 2 1 
7 8 9 1 6 4 3 5 2 
4 1 3 5 9 2 6 8 7 
2 6 5 7 8 3 4 1 9 
3 2 8 4 5 9 1 7 6 
6 9 4 2 7 1 5 3 8 
1 5 7 8 3 6 2 9 4 
```

### Functional decomposition into modules

We anticipate the following modules or functions:

 1. *main* which parses the arguments and initializes other modules accordingly
 2. *create* which randomly generates a randomized puzzle with at least 40 missing numbers
 3. *solve* which generates one solution for the puzzle without changing any numbers
 4. *common* which will declare data structures to represent the sudoku puzzle and will have functions relevant to creating, editing, printing, and checking sudoku puzzles

And a helper module that provides a data structure for the puzzle:

 1. *puzzle* of sudoku puzzle structure, a 9x9 array

### Pseudo code for logic/algorithmic flow

The sudoku will run as follows:
1. execute from a command line as shown in the User Interface
2. parse the command line arguments, checking the arguments for either `create` or `solve`
 3. if the argument is `create`, it will initialize the creator module
 4. if the argument is `solve`, it will load the puzzle from stdin
    5. use *puzzle_solve_forward* to solve the puzzle 

The solver will run as follows:
1. set two variables to later check whether all the rows and columns have been filled
2. use *find_next_unassigned* to find the next empty cell in the puzzle
3. if the puzzle has been solved that is there are no more empty cells, return true
4. if the puzzle still has empty cells
    5. loop through all the possible numbers to input (1-9)
    6. use *isValidInput* to check whether that number can be inserted or not
        7. if it is a valid input, then use *puzzle_insert* to insert the number into the specified cell
        8. use *puzzle_solve_forwards* to attempt to solve the puzzle using the validated number, if it works return true
    9. if there is no solution for the puzzle using the validated number, then use *cell_delete* to reset the coordinate and return false

The creator will run as follows:
1. make the board for the puzzle using a 9x9 array
2. set the seed for the random number generator
3. use *puzzle_new* to instantiate a new puzzle
4. use *puzzle_solve_random* to determine if the the puzzle is solvable by using backtracing
    5. if the puzzle is solvalble, randomize a number of cells to remove (set to 0) between 40 and 63 and set a variable holding how many cells have been removed
    6. while the number of cells that have been removed is less than the number of cells to remove
        7. use *clear_array* to set every cell in the puzzle to 0
        8. while there are still empty cells using *all_cells_tried*
            9. randomize the coordinates of the cell, that is the row and column
            10. if it is an empty cell, set it the cell to 1
            11. use *puzzle_lookup* to get the number at the specified coordinate in the puzzle
                12. set the returned number to a temporary variable
                13. use *cell_delete* to empty the cell (set it to 0) at that specified coordinate
                14. use *check_unique* to check that the puzzle still has a unique solution
                    15. if it is still unique, increment the number of cells that have been removed and break
                    16. if it is not unique, use *puzzle_insert* to insert another number
        17. if there are no more empty cells and the number of cells removed is greater than or equal to 40, return the puzzle
        18. if there are no more empty cells and the number of cells removed is less than 40, delete the puzzle and call *create* again
19. if *puzzle_solve_random* determines the puzzle is unsolvable, delete the puzzle and return NULL

A good implementation will not necessarily encode all the above code in a single, deeply-nested function; part of the Implementation Spec is to break the pseudocode down into a cleanly arranged set of functions.

### Dataflow through modules

The main function checks the inputs and, if valid, calls the appropriate function (create or solve). The sudoku creator creates a data structure that will house a randomly generated puzzle with a unique solutions. It will use various functions from the `common` directory to achieve this, as well as the use of random number generators. It will also utilize functions from the solver in order to produce a puzzle with a unique solution. The solver takes in a sudoku puzzle to be solved and, also using the functions in the `common` directory, finds a solution to the puzzle.

The main sudoku:
1. *main* parses the parameters and passses them to the indicated module, either create or solve

The creator module:
2. *create* returns a valid puzzle to solve with atleast 40 empty cells
3. *puzzle_solve_random* inserts random numbers into empty cells using backtracing to solve the puzzle
4. *clear_array* sets every cell in the puzzle to 0
5. *all_cells_tried* checks whether there are still empty cells (cells set to 0) in the puzzle
6. *puzzle_lookup* returns the number at the specified coordinates in the puzzle
7. *cell_delete* sets the cell to 0
8. *check_unique* checks whether the puzzle still has a unique solution by solving the puzzle forward and backward, then comparing the puzzles returned, if the same puzzle then it is unique

The solver module:
1. *puzzle_solve_forward* inserts lower numbers into empty cells first using backtracing to solve puzzle
2. *find_next_unassigned* returns the next coordinate that has the value of 0, that is finding the next empty cell
3. *is_valid_input* checks whether a given number can be inserted into a specific coordinate by checking if it satisfies the sudoku rules, that is checking its validity in the given row, column, and 3x3 grid
4. *puzzle_insert* inserts a number into a specified coordinate of the puzzle

### Major data structures

One helper module provides a data structure:

1. *puzzle* of sudoku puzzle structure, a 9x9 array

The `sudoku` data structure will hold the matrix that represents the sudoku puzzle.

### Testing plan
*Unit testing*.  A small test program to test each module to make sure it does what it's supposed to do. In both the creator and solver modules, unit testing will be ran to check modules individually. 

*Integration testing*.  Assemble the sudoku program and test it as a whole.
In each case, check that the puzzle outputted by the creator module is the same puzzle solved by the solver module.

*Fuzz testing*. A bash script for testing sudoku modules. We will create **n** random puzzles using the creator module, where **n** is a command-line argument. The script makes sure that the puzzle created has a unique solution. It then takes the output from each call to the creater and runs `./sudoku solve` to generate a solution to the puzzle that is valid following Sudoku rules.

Unit Testing: testing for both creator and solver modules. Unit testing will include checking the isUnique method to ensure that a given puzzle has a unique solution. We will also hardcode unsolvable puzzles and attempt to run `./sudoku solve` on them to ensure that the solver can recognize unsolvable puzzles.


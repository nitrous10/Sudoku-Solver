# Sudoku Design Spec

### User interface

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

Output: 9 lines of text that represent a solvable sudoku puzzle. If the command is `create`, the output is an random unsolved puzzle wwith a unique solution. If the command is `solve`, the output is a solved puzzle (the puzzle to solve is specified by the user).


### Functional decomposition into modules

*main* which parses the arguments and initialize other modules accordingly
*create* which randomly generates a randomized puzzle with at least 40 missing numbers
*solve* which generates one solution for the puzzle without changing any numbers
*common* which will declare data structures to represent the sudoku puzzle and will have functions relevant to creating, editing, printing, and checking sudoku puzzles.


### Pseudo code for logic/algorithmic flow

`create`
Insert numbers on the diagonal at random, repeats allowed. Insert numbers at random in each diagonal 3x3 grid, repeats not allowed. Run solve and find a solution. Remove random number of numbers between 40-60, checking after each removal if the puzzle solution is still unique. 


`Solver`
Read in the sudoku puzzle to solve.
Find the first occurrence of an unassigned box. If the puzzle cannot find an unassigned box and the puzzle is still valid, then the puzzle is solved. Otherwise, loop through each valid input for the unassigned block and see if that number leads to a solution (by calling solver on the new puzzle). If a valid input doesn't lead to a solution, backtrack and use the next valid number for a given box.


### Dataflow through modules

The main function checks the inputs and, if valid, calls the appropriate function (create or solve). The sudoku creator creates a data structure that will house a randomly generated puzzle with a unique solutions. It will use various functions from the `common` directory to achieve this, as well as the use of random number generators. It will also utilize functions from the solver in order to produce a puzzle with a unique solution. The solver takes in a sudoku puzzle to be solved and, also using the functions in the `common` directory, finds a solution to the puzzle.


### Major data structures

The `sudoku` data structure will hold the matrix that represents the sudoku puzzle.


### Testing plan
Fuzz testing: We will write a bash script that creates 10 random puzzles using the creator. The script then takes the output from each call to the creator and runs `./sudoku solve`. The script will also make sure that the puzzles created by the creator are unique.

Unit Testing: testing for both creator and solver modules. Unit testing will include checking the isUnique method to ensure that a given puzzle has a unique solution. We will also hardcode unsolvable puzzles and attempt to run `./sudoku solve` on them to ensure that the solver can recognize unsolvable puzzles.


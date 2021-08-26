# CS50 Summer 2021, Final Project, Sudoku
## Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen

### Solver module

This solver module contains functions necessary for solving a valid sudoku puzzle, along with functions necessary to check the uniqqueness of the puzzle and keep track of our empty cells. Our various functions for solving, that is *puzzle_solve_forwards*, *puzzle_solve_backwards*, and *puzzle_solve_random* each solve a Sudoku puzzle using backtracing while checking the validity of the inputs. 

The user can run unit testing on this module. In order to run the unit testing, uncomment the main function defined at the bottom of solver.c
and add the appropriate testing flags within the makefile. 

To build, run `make`.

To clean up, run `make clean`.
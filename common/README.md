# CS50 Summer 2021, Final Project, Sudoku
## Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen

### common library

To build, run `make`.

To clean up, run `make clean`.

This common library contains functions that are used in both the creator and solver modules, along with defining our puzzle data structure. These functions include those to validate the inputs of the puzzles, that is making sure the numbers satisfy the Sudoku rules. Our sudoku program internally uses these functions as it calls the functions in our creator and solver modules. 
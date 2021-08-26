# CS50 Summer 2021, Final Project, Sudoku
## Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen

Our Sudoku program can create a random Sudoku puzzle with a unique solution atleast 40 empty cells by running `./sudoku create`. It can also solve a given Sudoku puzzle that is validated by running `./sudoku solve`. Both our creator and solver ensure that the puzzles satisfy the Sudoku rules, that is that a number 1 through 9 appears only once in a row, once in a column, and once in a 3x3 squared region.

One thing to note is that `./sudoku create` may take some time to run as with more empty cells, it is more difficult to solve a puzzle, thus takes more iterations. 

Refer to DESIGN.md and IMPLEMENTATION.md for specific implementation and design overviews in the overall Sudoku program, each module: create and solver, and our common library: sudokulib. 

Our TESTING.md contains our memory checks using valgrind.

To build, run `make`.

To test, `make test` which runs our fuzz testing.

To clean up, run `make clean`.
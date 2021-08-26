/**
 * sudoku.c - contains functions that help create sudoku puzzles
 * 
 * CS50, Summer 2021
 * Authors: Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen
 */


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sudokulib.h"
#include "solver.h"
#include "create.h"


int main(int argc, char const *argv[]) {
    if(argc != 2){
		fprintf(stderr, "usage: ./sudoku (solve/create)\n");
		exit(1);
	}

    if (strcmp(argv[1], "create") == 0) {
        puzzle_t *puzzle = create();
        puzzle_print(puzzle, stdout);
        puzzle_delete(puzzle);
    } else if (strcmp(argv[1], "solve") == 0) {
        puzzle_t *puzzle = puzzle_load(stdin);
        if (puzzle == NULL || !puzzle_solve_forwards(puzzle)) {
            fprintf(stderr, "puzzle is unsolvable\n" );
            exit(2);
        } 
        puzzle_solve_forwards(puzzle);
        puzzle_print(puzzle, stdout);
        puzzle_delete(puzzle);
    } else {
        fprintf(stderr, "usage: ./sudoku (solve/create)\n");
		exit(3);
    }
    return 0;
}
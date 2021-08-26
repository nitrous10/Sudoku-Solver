/**
 * create.c - contains functions that help create sudoku puzzles
 * 
 * CS50, Summer 2021
 * Authors: Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen
 */

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "create.h"



typedef struct puzzle {
    int array[size][size];
} puzzle_t;


/**
 *
 * create() - Function to create a valid puzzle
 *  makes board
 *  calls puzzle_solve_random
 *  chooses a random number between 40 and 63 which will be the number of blanks
 *  delete that many cells with cell_delete and check_unique
 *  if we get to a point where there is no possible cell to delete, we return the puzzle as is. In final version, it should start over removing from the puzzle.
 *  returns NULL if fails to create puzzle, 
 */

puzzle_t* create() {
    int array[9][9];
    srand(time(NULL));
    puzzle_t *puzzle = puzzle_new();
    if (puzzle_solve_random(puzzle)) {
        int num_to_remove = (rand() % 24) + 40;
        int removed = 0;
        while (removed < num_to_remove) {
            clear_array(array);
            while(!all_cells_tried(array)){
                int row = (rand() % 9);
                int col = (rand() % 9);
                if (array[row][col] == 0){
                    array[row][col] = 1;
                    if (puzzle_lookup(puzzle, row, col) != 0) {
                        int temp = puzzle_lookup(puzzle, row, col);
                        cell_delete(puzzle, row, col);
                        if (check_unique(puzzle)){
                            removed++;
                            clear_array(array);
                            break;
                        }
                        else {
                            puzzle_insert(puzzle, row, col, temp);
                        }
                    }
                }
            }
            if (all_cells_tried(array) && removed >= 40) {
                return puzzle;
            } else if(all_cells_tried(array) && removed < 40) {
                puzzle_delete(puzzle);
                return create();
            }
        }
        return puzzle;
    }
    fprintf(stderr, "Failed to create puzzle because puzzle_solve_random returned false\n");
    puzzle_delete(puzzle);
    return NULL;
}


// puzzle create helper
bool all_cells_tried(int array[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (array[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// make every value in the array 0
void clear_array (int array[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            array[i][j] = 0;
        }
    }
}

int num_empty_cells(puzzle_t *puzzle){
    int count = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (puzzle_lookup(puzzle, i,j) == 0){
                count++;
            }
        }
    }
    return count;
}

#ifdef UNIT_TEST
int main(int argc, char const *argv[])
{
    puzzle_t *puzzle = create();
    if (puzzle != NULL){
        if (check_unique(puzzle)){
            //puzzle_print(puzzle, stdout);
            int num_empty = num_empty_cells(puzzle);
            fprintf(stdout, "Number of empty cells: %d\n", num_empty);
        }
        else {
            fprintf(stderr, "puzzle created is not a unique puzzle\n");
            puzzle_delete(puzzle);
            return 2;
        }
    }
    else {
        fprintf(stderr, "create() failed to create a puzzle\n");
        puzzle_delete(puzzle);
        return 1;
    }
    puzzle_delete(puzzle);
    return 0;
}
#endif

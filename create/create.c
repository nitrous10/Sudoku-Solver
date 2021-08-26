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


/**************** create ****************/
/* create() - Function to generate a valid puzzle  
 * calls puzzle_new to make the board
 * calls puzzle_solve_random to determine if the puzzle is solvable
 * chooses a random number between 40 and 63 that will be the number of empty cells in the puzzle
 * deletes that number of cells using cell_delete
 * checks thats the puzzle still has a unique solution using check_unique
 * if there are no more cells to delete, checked using all_cells_tried, and the number of cells removed is greater than or equal to 40 then return the puzzle
 * if there are no more cells to delete, but the number of cells removed is less than 40, call create again
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


/**************** all_cells_tried ****************/
/* Checks if there are no cells to remove that preserve a unique solution
 * the array we pass will have a zero in the position corresponding to every cell we have not checked
 * Thus, if any cell has a zero, we have not yet tried it, and our function returns false
 * Otherwise, return true
 */bool all_cells_tried(int array[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (array[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

/**************** clear_array ****************/
/* go through the array storing what cells we have tried to remove, 
 * and reset every cell to 0, (essentially saying we have not yet tried to remove any cells
 * 
 */void clear_array (int array[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            array[i][j] = 0;
        }
    }
}

/**************** num_empty_cells ****************/
/* returns the number of blank cells in a puzzle
 * 
 */
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
// int main(int argc, char const *argv[])
// {
//     puzzle_t *puzzle = create();
//     if (puzzle != NULL){
//         if (check_unique(puzzle)){
//             //puzzle_print(puzzle, stdout);
//             int num_empty = num_empty_cells(puzzle);
//             fprintf(stdout, "Number of empty cells: %d\n", num_empty);
//         }
//         else {
//             fprintf(stderr, "puzzle created is not a unique puzzle\n");
//             puzzle_delete(puzzle);
//             return 2;
//         }
//     }
//     else {
//         fprintf(stderr, "create() failed to create a puzzle\n");
//         puzzle_delete(puzzle);
//         return 1;
//     }
//     puzzle_delete(puzzle);
//     return 0;
// }
#endif

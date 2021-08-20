/*
 * sudokulib.c - helper functions for sudoku modules
 *
 * Written in collaboration by Melissa Valencia, Noah Yusen, 
 * Clay Papanek, and Emily Zhou
 * 
 * See sudokulib.h for more information
 * 
 * CS50 Summer 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define size 9

typedef struct puzzle {
    int array[size][size];
} puzzle_t;


puzzle_t *puzzle_new() {
    puzzle_t *puzzle = count_malloc(sizeof(puzzle_t));

    if (puzzle == NULL) {
        return NULL;
    } else {
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                puzzle->array[i][j] = 0;
            }
        }
    }
    return puzzle;
}

void puzzle_delete(puzzle_t *puzzle) {
    if (puzzle != NULL) {
        free(puzzle);
    }
}

void cell_delete(puzzle_t *puzzle, int row, int col) {
    if (puzzle != NULL) {
        puzzle->array[row][col] = 0;
    }
}

void puzzle_insert(puzzle_t *puzzle, int row, int col, int insertNum) {
    if (puzzle != NULL) {
        puzzle->array[row][col] = insertNum;
    }
}

void puzzle_print(puzzle_t *puzzle, FILE *fp) {
  if (puzzle == NULL || fp == NULL) return;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      fprintf(fp, "%d ", puzzle->array[i][j]);
    }
    fprintf(fp, "\n");
  }
}

puzzle_t *puzzle_load(FILE *fp) {
    if (fp == NULL){
        return NULL;
    }
    puzzle_t *puzzle = puzzle_new();
    if (puzzle == NULL) {
        return NULL;
    }
    int row = 0;
    int col = 0;
    int temp = 0;
    while(fscanf(fp, "%d ", &temp) == 1) {
        puzzle->array[row][col] = temp;
        col++;
        if (col == 9) {
            col = 0;
            row++;
        }
        if (row == 9) {
            break;
        }
    }
    return puzzle;
}

bool compare_puzzles(puzzle_t *p1, puzzle_t *p2) {
    if (p1 == NULL || p2 == NULL) {
        return false;
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            if (p1->array[i][j] != p2->array[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool isValidInput(int array[size][size], int row, int col, int insertNum) {
    // Check row
    for (int i = 0; i <= 8; i++) {
        if (array[row][i] == insertNum) {
            return false;
        }
    }

    // Check col
    for (int i = 0; i <= 8; i++) {
        if (array[i][col] == insertNum) {
            return false;
        }
    }

    // Check 3x3
    int smallRow = (row/3)* 3;
    int smallCol = (col/3) * 3;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (array[smallRow + i][smallCol + j] == insertNum) {
                return false;
            }
        }
    }
    return true;
}
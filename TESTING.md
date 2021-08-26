# Testing Procedure

In order to test our program, we created a bash script called `fuzztesting.sh`, run using `make test` or `./fuzztesting.sh [numPuzzles]`, where `numPuzzles` is the number of puzzles that the user wishes to create and then solve. The testing program calls `./sudoku create`, writes the output to a file, and then calls `./sudoku solve` using the created file as input. The program prints both the unsolved puzzle and the solved puzzle to the terminal. The testing program also calls `./sudoku` with different invalid parameters in order to test whether the program can catch invalid arguments.

Note: We also performed manual testing on `./sudoku solve`, in which we fed the solver invalid puzzles, valid puzzles, and attempts to create puzzles with non-integer values and integer values outside of the range [0-9].

Below is the testing output for running `./fuzztesting.sh 4` (with added valgrind commands to check for memory leaks):

```
testing sudoku
usage: ./sudoku (solve/create)
usage: ./sudoku (solve/create)
usage: ./sudoku (solve/create)
Iteration 1:
==46255== Memcheck, a memory error detector
==46255== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46255== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46255== Command: ./sudoku create
==46255== 
==46255== 
==46255== HEAP SUMMARY:
==46255==     in use at exit: 0 bytes in 0 blocks
==46255==   total heap usage: 88 allocs, 88 frees, 36,380 bytes allocated
==46255== 
==46255== All heap blocks were freed -- no leaks are possible
==46255== 
==46255== For counts of detected and suppressed errors, rerun with: -v
==46255== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Created Puzzle:
8 2 0 0 0 5 4 7 0 
0 0 1 7 4 8 0 0 0 
7 4 0 9 0 0 0 8 6 
0 0 0 4 6 0 0 2 8 
0 8 6 0 7 0 0 5 1 
9 0 0 0 0 1 0 0 0 
0 9 0 0 0 7 8 0 0 
2 0 7 1 8 0 0 4 0 
0 6 8 0 9 4 5 1 0 
Solved Puzzle:
==46277== Memcheck, a memory error detector
==46277== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46277== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46277== Command: ./sudoku solve
==46277== 
8 2 9 6 1 5 4 7 3 
6 3 1 7 4 8 2 9 5 
7 4 5 9 2 3 1 8 6 
5 1 3 4 6 9 7 2 8 
4 8 6 3 7 2 9 5 1 
9 7 2 8 5 1 6 3 4 
1 9 4 5 3 7 8 6 2 
2 5 7 1 8 6 3 4 9 
3 6 8 2 9 4 5 1 7 
==46277== 
==46277== HEAP SUMMARY:
==46277==     in use at exit: 0 bytes in 0 blocks
==46277==   total heap usage: 4 allocs, 4 frees, 9,864 bytes allocated
==46277== 
==46277== All heap blocks were freed -- no leaks are possible
==46277== 
==46277== For counts of detected and suppressed errors, rerun with: -v
==46277== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Iteration 2:
==46315== Memcheck, a memory error detector
==46315== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46315== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46315== Command: ./sudoku create
==46315== 
==46315== 
==46315== HEAP SUMMARY:
==46315==     in use at exit: 0 bytes in 0 blocks
==46315==   total heap usage: 98 allocs, 98 frees, 39,620 bytes allocated
==46315== 
==46315== All heap blocks were freed -- no leaks are possible
==46315== 
==46315== For counts of detected and suppressed errors, rerun with: -v
==46315== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Created Puzzle:
2 5 6 0 0 0 1 0 0 
0 0 0 0 8 0 5 3 0 
0 8 0 4 0 0 0 0 0 
3 0 5 1 7 2 0 0 4 
0 7 0 0 0 8 6 0 0 
0 1 0 0 6 0 0 0 0 
0 2 0 8 1 4 3 9 0 
0 4 1 0 0 3 0 7 2 
8 0 0 5 0 0 0 0 0 
Solved Puzzle:
==46330== Memcheck, a memory error detector
==46330== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46330== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46330== Command: ./sudoku solve
==46330== 
2 5 6 7 3 9 1 4 8 
1 9 4 2 8 6 5 3 7 
7 8 3 4 5 1 2 6 9 
3 6 5 1 7 2 9 8 4 
9 7 2 3 4 8 6 5 1 
4 1 8 9 6 5 7 2 3 
6 2 7 8 1 4 3 9 5 
5 4 1 6 9 3 8 7 2 
8 3 9 5 2 7 4 1 6 
==46330== 
==46330== HEAP SUMMARY:
==46330==     in use at exit: 0 bytes in 0 blocks
==46330==   total heap usage: 4 allocs, 4 frees, 9,864 bytes allocated
==46330== 
==46330== All heap blocks were freed -- no leaks are possible
==46330== 
==46330== For counts of detected and suppressed errors, rerun with: -v
==46330== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Iteration 3:
==46355== Memcheck, a memory error detector
==46355== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46355== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46355== Command: ./sudoku create
==46355== 
==46355== 
==46355== HEAP SUMMARY:
==46355==     in use at exit: 0 bytes in 0 blocks
==46355==   total heap usage: 104 allocs, 104 frees, 41,564 bytes allocated
==46355== 
==46355== All heap blocks were freed -- no leaks are possible
==46355== 
==46355== For counts of detected and suppressed errors, rerun with: -v
==46355== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Created Puzzle:
1 0 0 9 0 4 7 0 0 
0 0 0 8 0 0 0 0 1 
9 0 5 0 1 0 0 0 0 
5 4 0 0 0 0 2 0 0 
0 9 7 0 8 0 4 0 5 
0 0 0 0 0 5 0 0 9 
3 0 0 0 6 0 0 7 2 
0 6 0 0 0 1 3 4 0 
4 7 1 0 0 0 0 9 6 
Solved Puzzle:
==46365== Memcheck, a memory error detector
==46365== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46365== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46365== Command: ./sudoku solve
==46365== 
1 8 6 9 2 4 7 5 3 
7 2 4 8 5 3 9 6 1 
9 3 5 6 1 7 8 2 4 
5 4 3 1 9 6 2 8 7 
6 9 7 3 8 2 4 1 5 
8 1 2 7 4 5 6 3 9 
3 5 8 4 6 9 1 7 2 
2 6 9 5 7 1 3 4 8 
4 7 1 2 3 8 5 9 6 
==46365== 
==46365== HEAP SUMMARY:
==46365==     in use at exit: 0 bytes in 0 blocks
==46365==   total heap usage: 4 allocs, 4 frees, 9,864 bytes allocated
==46365== 
==46365== All heap blocks were freed -- no leaks are possible
==46365== 
==46365== For counts of detected and suppressed errors, rerun with: -v
==46365== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Iteration 4:
==46401== Memcheck, a memory error detector
==46401== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46401== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46401== Command: ./sudoku create
==46401== 
==46401== 
==46401== HEAP SUMMARY:
==46401==     in use at exit: 0 bytes in 0 blocks
==46401==   total heap usage: 156 allocs, 156 frees, 58,412 bytes allocated
==46401== 
==46401== All heap blocks were freed -- no leaks are possible
==46401== 
==46401== For counts of detected and suppressed errors, rerun with: -v
==46401== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Created Puzzle:
0 7 1 8 3 0 0 0 4 
0 0 0 0 0 0 0 8 0 
0 3 0 0 0 0 7 0 0 
0 9 0 0 0 1 0 0 0 
7 4 0 0 0 0 0 5 0 
0 0 6 0 0 0 2 3 9 
0 0 4 0 7 3 0 0 1 
0 0 0 6 0 0 8 0 0 
0 0 0 9 8 5 0 4 0 
Solved Puzzle:
==46715== Memcheck, a memory error detector
==46715== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==46715== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==46715== Command: ./sudoku solve
==46715== 
5 7 1 8 3 9 6 2 4 
4 6 2 1 5 7 9 8 3 
8 3 9 4 2 6 7 1 5 
2 9 3 5 6 1 4 7 8 
7 4 8 3 9 2 1 5 6 
1 5 6 7 4 8 2 3 9 
9 8 4 2 7 3 5 6 1 
3 2 5 6 1 4 8 9 7 
6 1 7 9 8 5 3 4 2 
==46715== 
==46715== HEAP SUMMARY:
==46715==     in use at exit: 0 bytes in 0 blocks
==46715==   total heap usage: 4 allocs, 4 frees, 9,864 bytes allocated
==46715== 
==46715== All heap blocks were freed -- no leaks are possible
==46715== 
==46715== For counts of detected and suppressed errors, rerun with: -v
==46715== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Success
```
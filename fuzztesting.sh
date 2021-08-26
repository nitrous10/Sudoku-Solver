#!/bin/bash
#
# Testing file for sudoku
# Usage: ./fuzztesting.sh [numPuzzles], where numPuzzles is an integer
# 
# Tests the ./sudoku create and ./sudoku solve functions by piping output from ./sudoku create to ./sudoku solve
# Solves a user-specified number of puzzles (numPuzzles)
#
# CS50, Summer 2021
# Authors: Clay Papanek, Emily Zhou, Melissa Valencia, and Noah Yusen
#
#

# ============ Functionality test =======#

############################################################

echo testing sudoku

numtests=1

if [ "$#" -ne 1 ]; then
    echo "Usage: ./fuzztesting.sh [numPuzzles]"
    exit 1;
fi

re='^[0-9]+$'
if ! [[ "$1" =~ $re ]] ; then
    echo "Argument is not an integer" >&2; exit 2
fi
numtests=$1

./sudoku many words
if [ $? -ne 1 ]; then
    echo "Failed test with too many args"
    exit 3
fi

./sudoku
if [ $? -ne 1 ]; then
    echo "Failed test with not enough args"
    exit 4
fi

./sudoku NotSolveOrCreate
if [ $? -ne 3 ]; then
    echo "Failed test with word that isn't solve or create"
    exit 5
fi

i=1
while [ "$i" -le "$numtests" ];
do
    sleep 1 # Enough time for random seed to update
    echo "Iteration $i:"
    ./sudoku create > puzzleFile.txt
    if [ $? -ne 0 ]; then
        echo "Create Failed"
        exit 6
    fi
    echo "Created Puzzle:"
    cat puzzleFile.txt

    echo "Solved Puzzle:"
    ./sudoku solve < puzzleFile.txt
    if [ $? -ne 0 ]; then
        echo "Solve Failed"
        exit 7
    fi
    echo ""
    i=$(($i + 1))
done

echo "Success"
exit 0



 

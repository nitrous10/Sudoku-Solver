#!/bin/bash
#
# Testing file for sudoku
#
#
#
#

# ============ Functionality test =======#

# directories

mkdir -p createdpuzzle

############################################################

echo testing sudoku

numtests=1
if [ $# -eq 1]; then
    numtests=$1
fi

for i in {1..$numtests}
do
    ./sudoku create > puzzleFile.txt
    cat puzzleFile.txt | ./sudoku solve
done





# ============== Memory Check ===================
myvalgrind='valgrind --leak-check=full --show-leak-kinds=all'
DATAVAL=../data/valgrind
SEED=http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
DEPTH=6

mkdir -p $DATAVAL
$myvalgrind ./crawler $SEED $DATAVAL $DEPTH
rm -rf $DATAVAL




 

#
# Makefile for solver directory which contains helper functions for solving sudoku puzzles
#
# Written in collaboration by Melissa Valencia, Noah Yusen, 
# Clay Papanek, and Emily Zhou
# 
# CS50 Summer 2021
# 
#

#TESTFLAGS = -DUNIT_TEST1
CFLAGS = -Wall -pedantic -std=c11 -ggdb  -I../common
LIBS = ../common/common.a
CC = gcc
MAKE = make

solver: solver.o
	$(CC) $(CFLAGS) solver.o $(LIBS) -o $@

solver.o:

.PHONY: clean

clean:
	rm -f solver
	rm -f *.o
	
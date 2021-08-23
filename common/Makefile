#
# Makefile for common directory which contains helper functions for sudoku modules
#
# Written in collaboration by Melissa Valencia, Noah Yusen, 
# Clay Papanek, and Emily Zhou
# 
# CS50 Summer 2021
# 
#


OBJS = sudokulib.o
LIB = common.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb
CC = gcc
MAKE = make



$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)


sudokulib.o: sudokulib.h


.PHONY: clean


clean:
	rm -rf *.dSYM 
	rm -f core
	rm -f $(LIB) *~ *.o
	rm -f *.a
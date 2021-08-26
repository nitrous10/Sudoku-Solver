# Makefile for Sudoku
#
# CS 50, Summer 2021

OBJS = sudoku.o
LIB = common.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I./create -I./solver -I./common 
CC = gcc
MAKE = make


sudoku: sudoku.o ./common/common.a ./solver/solver.o ./create/create.o
solver.o:
create.o:

.PHONY: test valgrind clean

############## default: make all libs and programs ##########
test: 
	make -C common
	make -C create
	make -C solver

############## valgrind all programs ##########
#valgrind: all
#make -C common valgrind
#make -C indexer valgrind
#make -C querier valgrind


############## clean  ##########
clean:
	rm -f *~
	make -C common clean
	make -C create clean
	make -C solver clean

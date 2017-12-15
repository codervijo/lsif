# Makefile to build Podcomm server C code

CC=gcc
CFLAGS=-Wall

lsif: lsif.c

clean:
	rm -f *.o lsif

help:
	@echo "make : Builds lsif"
	@echo "make clean : Remove all object/executable files"

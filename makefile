OBJECTS=functional.o
CFLAGS = -std=c99 -g -Wall
LDLIBS=-lm
CC=gcc

$(P): $(OBJECTS)

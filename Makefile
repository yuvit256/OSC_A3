CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) isort.o -o isort

txtfind: txtfind.o
	$(CC) $(FLAGS) txtfind.o -o txtfind

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

clean:
	rm -f *.o txtfind isort
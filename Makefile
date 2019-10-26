CC = gcc
CF = -c
OF = -o

all: test_ht

test_ht: test_ht.o
	$(CC) $(OF) test_ht test_ht.o

test_ht.o: test_ht.cpp
	$(CC) $(CF) test_ht.cpp
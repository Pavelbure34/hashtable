CC = g++
CF = -c
OF = -o

all: test_ht

test_ht: test_ht.o
	$(CC) $(OF) test_ht test_ht.o

test_ht.o: test_ht.cpp List.h List.cpp hash_table.h hash_table.cpp
	$(CC) $(CF) test_ht.cpp
CC = g++
CF = -c
OF = -o

all: test_ht scrabble test_dict imdb2

scrabble: scrabble.o
	$(CC) $(OF) scrabble scrabble.o

scrabble.o: scrabble.cpp List.h List.cpp hash_table.h hash_table.cpp
	$(CC) $(CF) scrabble.cpp

test_ht: test_ht.o
	$(CC) $(OF) test_ht test_ht.o

imdb2: imdb2.o
	$(CC) $(OF) imdb2 imdb2.o

test_ht.o: test_ht.cpp List.h List.cpp hash_table.h hash_table.cpp
	$(CC) $(CF) test_ht.cpp

test_dict: test_dict.o
	$(CC) $(OF) test_dict test_dict.o

test_dict.o: test_dict.cpp List.h List.cpp hash_table.h hash_table.cpp
	$(CC) $(CF) test_dict.cpp

imdb2.o: imdb2.cpp test_dict.cpp List.h List.cpp hash_table.h hash_table.cpp
	$(CC) $(CF) imdb2.cpp
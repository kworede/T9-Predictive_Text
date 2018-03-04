CC = gcc
C_OPT = -Wall
SOURCE_C = trie.c triemaker.c
OBJECTS = trie.o triemaker.o

trie.o: trie.c trie.h
	$(CC) $(C_OPT) -c $<

triemaker.o: triemaker.c triemaker.h
	$(CC) $(C_OPT) -c $<

t9:  trie.o triemaker.o
	$(CC) $(C_OPT) -o $@ $^

clean:
	rm t9 $(OBJECTS)

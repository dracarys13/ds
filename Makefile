CC = g++
CCFLAGS = -Wall -g
TARGET = TrieTest IndexMinPQTest

all: $(TARGET)

%: %.cc %.h
	$(CC) $(CCFLAGS) -o $@ $< 

Trie.o: Trie.cc Trie.h
	$(CC) $(CCFLAGS) -o $@ -c $< 

TrieTest: TrieTest.cc Trie.o
	$(CC) $(CCFLAGS) -o $@ $^ 

IndexMinPQTest: IndexMinPQTest.cc IndexMinPQ.h
	$(CC) $(CCFLAGS) -o $@ $^ 

.PHONY: clean
clean:
	rm $(TARGET) *.o

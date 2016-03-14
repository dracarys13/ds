CC = g++
CCFLAGS =  -Wall -g

TARGET = SkipListTest SplayBSTTest HashTableTest

all: $(TARGET) 

SkipList.o: SkipList.cc SkipList.h
	$(CC) $(CCFLAGS) -o $@ -c $<

SkipListTest: SkipListTest.cc SkipList.o
	$(CC) $(CCFLAGS) -o $@ $^

SplayBSTTest: SplayBSTTest.cc SplayBST.h
	$(CC) $(CCFLAGS) -o $@ $^

HashTableTest:HashTableTest.cc HashTable.h HashFunc.h
	$(CC) $(CCFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

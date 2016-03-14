CC = g++
CCFLAGS =  -Wall -g

TARGET = SkipListTest

all: $(TARGET) 

SkipList.o: SkipList.cc SkipList.h
	$(CC) $(CCFLAGS) -o $@ -c $<

SkipListTest: SkipListTest.cc SkipList.o
	$(CC) $(CCFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

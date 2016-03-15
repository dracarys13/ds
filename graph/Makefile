CC = g++
CCFLAGS =  -g
TARGET = EdgeWeightedGraphTest PrimMSTTest
all: $(TARGET) 

#############
UF.o: UF.cc UF.h
	$(CC) $(CCFLAGS) -c $<
#############
Edge.o: Edge.cc Edge.h  # 无向带权边
	$(CC) $(CCFLAGS) -c $<
EdgeWeightedGraph.o: EdgeWeightedGraph.cc EdgeWeightedGraph.h  # 无向带权图
	$(CC) $(CCFLAGS) -c $<
PrimMST.o: PrimMST.cc PrimMST.h
	$(CC) $(CCFLAGS) -c $<
EdgeWeightedGraphTest: EdgeWeightedGraphTest.cc EdgeWeightedGraph.o Edge.o
	$(CC) $(CCFLAGS) -o $@ $^
PrimMSTTest: PrimMSTTest.cc PrimMST.o EdgeWeightedGraph.o Edge.o
	$(CC) $(CCFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

CC = g++
CCFLAGS =  -g
TARGET = EdgeWeightedGraphTest PrimMSTTest KruskalMSTTest DijkstraSPTest
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
#############
KruskalMST.o: KruskalMST.cc KruskalMST.h
	$(CC) $(CCFLAGS) -c $<
KruskalMSTTest: KruskalMSTTest.cc KruskalMST.o EdgeWeightedGraph.o Edge.o UF.o
	$(CC) $(CCFLAGS) -o $@ $^
############
DirectedEdge.o: DirectedEdge.cc DirectedEdge.h #有向带权边
	$(CC) $(CCFLAGS) -c $<
EdgeWeightedDigraph.o: EdgeWeightedDigraph.cc EdgeWeightedDigraph.h  # 有向带权图
	$(CC) $(CCFLAGS) -c $<
DijkstraSP.o: DijkstraSP.cc DijkstraSP.h
	$(CC) $(CCFLAGS) -c $<
DijkstraSPTest: DijkstraSPTest.cc DijkstraSP.o EdgeWeightedDigraph.o DirectedEdge.o
	$(CC) $(CCFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

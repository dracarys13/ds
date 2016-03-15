#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H
#include <vector>
#include <iostream>
#include "Edge.h"

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph(std::istream &in);
    int v();
    int e();
    void addEdge(Edge e);
    std::vector<Edge> adj(int v);
    std::vector<Edge> edges();
    void toString();
private:
    int v_;
    int e_;
    std::vector<std::vector<Edge> > adj_;
    std::vector<Edge> edges_;
};
#endif

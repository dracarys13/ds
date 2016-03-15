#ifndef EDGEWEIGHTEDDIGRAPH_H
#define EDGEWEIGHTEDDIGRAPH_H

#include "DirectedEdge.h"
#include <vector>
#include <iostream>

class EdgeWeightedDigraph {
private:
    int v_;
    int e_;
    std::vector<std::vector<DirectedEdge> > adj_;
    std::vector<DirectedEdge> edges_;
public:
    EdgeWeightedDigraph(std::istream &in);
    int v();
    int e();
    void addEdge(DirectedEdge e);
    std::vector<DirectedEdge> edges();
    std::vector<DirectedEdge> adj(int v);
    void toString();
};
#endif

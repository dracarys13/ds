#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H

#include "EdgeWeightedDigraph.h"
#include "DirectedEdge.h"
#include <vector>
#include <queue>

struct HeapNode {
    int v;
    double weight;
    bool operator<(const HeapNode &rhs) const {
        return weight > rhs.weight;
    }
};

class DijkstraSP {
public:
    DijkstraSP(EdgeWeightedDigraph &g, int s);
    void relax(EdgeWeightedDigraph &g, int v);
    std::vector<DirectedEdge> pathTo(int v);
private:
    int s_;
    std::vector<double> dist_to_;
    std::vector<DirectedEdge> edge_to_;
    std::priority_queue<HeapNode> pq_;
    std::vector<bool> marked_;
};
#endif

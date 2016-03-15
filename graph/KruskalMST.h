#ifndef KRUSKALMST_H
#define KRUSKALMST_H
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include <vector>
#include <queue>

struct EdgeCompare {
    bool operator()(Edge &a, Edge &b) {
        return a.weight() > b.weight();
    }
};

class KruskalMST {
public:
    KruskalMST(EdgeWeightedGraph &g);
    std::vector<Edge> edges();
    int weight();
private:
    std::vector<Edge> mst_;
    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> pq_;
    double weight_;
};
#endif

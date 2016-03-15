#ifndef PRIMMST_H
#define PRIMMST_H
// reference: http://algs4.cs.princeton.edu/43mst/PrimMST.java.html
#include "EdgeWeightedGraph.h"
#include "Edge.h"
#include <queue>
#include <vector>

struct Distance {
    int v;
    double distance;
    bool operator<(const Distance &rhs) const {
        return distance > rhs.distance;  // 小顶堆
    }
};

class PrimMST {
public:
    PrimMST(EdgeWeightedGraph &g);
    std::vector<Edge> edges();
private:
    std::vector<int> marked_;
    std::vector<double> dist_;
    std::vector<Edge> edges_;
    std::vector<Edge> edge_to_;
    std::priority_queue<Distance> pq_;
};
#endif

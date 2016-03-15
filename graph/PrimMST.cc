#include "PrimMST.h"
#include <stdio.h>

double INF = 1e100;

PrimMST::PrimMST(EdgeWeightedGraph &g) {
    marked_.assign(g.v(), false);
    edge_to_.resize(g.v());
    dist_.assign(g.v(), INF);
    dist_[0] = 0.0;
    pq_.push((Distance) {0, 0.0});
    while (!pq_.empty()) {
        Distance nearest = pq_.top();
        int v = nearest.v;
        pq_.pop();
        if (marked_[v]) {
            continue;
        }
        marked_[v] = true;
        std::vector<Edge> adj = g.adj(v);
        for (std::vector<Edge>::iterator it = adj.begin(); it != adj.end(); ++it) {
            int w = (*it).other(v);
            // printf("v:%d w%d dist_[v]:%.2f  weight:%.2f dist[w]:%.2f\n", v, w, dist_[v], (*it).weight(), dist_[w]);
            if (!marked_[w] && (*it).weight() < dist_[w]) { // relax 注意是离树的距离而不是离0的距离
                // printf("relax\n");
                dist_[w] = (*it).weight();
                edge_to_[w] = *it;
                pq_.push((Distance) {w, dist_[w]});
            }
        }
    }
}

std::vector<Edge> PrimMST::edges() {
    std::vector<Edge> edges;
    for (int i = 1; i < edge_to_.size(); ++i) { // 0 is source, so edge_to_[0] not exist
        edges.push_back(edge_to_[i]);
    }
    return edges;
}

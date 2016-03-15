#include "DijkstraSP.h"
#include <algorithm>

double INF = 1e100;

DijkstraSP::DijkstraSP(EdgeWeightedDigraph &g, int s): s_(s) {
    dist_to_.assign(g.v(), INF);
    edge_to_.resize(g.v());
    marked_.assign(g.v(), false);
    dist_to_[s] = 0.0;
    pq_.push((HeapNode) {s, 0.0});
    while (!pq_.empty()) {
        HeapNode relaxNode = pq_.top();
        pq_.pop();
        if (marked_[relaxNode.v]) {
            continue;
        }
        marked_[relaxNode.v] = true;
        relax(g, relaxNode.v);
    }
}

void DijkstraSP::relax(EdgeWeightedDigraph &g, int v) {
    std::vector<DirectedEdge> adj = g.adj(v);
    for (int i = 0; i < adj.size(); ++i) {
        int w = adj[i].to();
        if (dist_to_[v] + adj[i].weight() < dist_to_[w]) {
            dist_to_[w] = dist_to_[v] + adj[i].weight();
            edge_to_[w] = adj[i];
            pq_.push((HeapNode) {w, dist_to_[w]});
        }
    }
}

std::vector<DirectedEdge> DijkstraSP::pathTo(int v) {
    std::vector<DirectedEdge> paths;
    for (int x = v; x != s_; x = edge_to_[x].from()) {
        paths.push_back(edge_to_[x]);
    }
    std::reverse(paths.begin(), paths.end());
    return paths;
}

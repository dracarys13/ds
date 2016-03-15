#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"
#include <stdio.h>

EdgeWeightedDigraph::EdgeWeightedDigraph(std::istream &in) {
    in >> v_;
    in >> e_;
    adj_.assign(v_, std::vector<DirectedEdge>());
    int from, to;
    double weight;
    while (in >> from && in >> to && in >> weight) {
        DirectedEdge e(from, to, weight);
        edges_.push_back(e);
        addEdge(e);
    }
}

int EdgeWeightedDigraph::v() {
    return v_;
}

int EdgeWeightedDigraph::e() {
    return e_;
}

void EdgeWeightedDigraph::addEdge(DirectedEdge e) {
    int from = e.from();
    adj_[from].push_back(e);
}

std::vector<DirectedEdge> EdgeWeightedDigraph::edges() {
    return edges_;
}

std::vector<DirectedEdge> EdgeWeightedDigraph::adj(int v) {
    return adj_[v];
}

void EdgeWeightedDigraph::toString() {
    for (int i = 0; i < v_; ++i) {
        for (int j = 0; j < adj_[i].size(); ++j) {
            adj_[i][j].toString();
        }
        printf("\n");
    }
}

#include "EdgeWeightedGraph.h"

EdgeWeightedGraph::EdgeWeightedGraph(std::istream &in) {
    in >> v_;
    in >> e_;
    adj_.assign(v_, std::vector<Edge>());
    int v, w;
    double weight;
    while (in >> v && in >> w && in >> weight) {
        Edge e(v, w, weight);
        edges_.push_back(e);
        addEdge(e);
        std::cout << v << " " << w << " " << weight << std::endl;
    }
}

int EdgeWeightedGraph::v() {
    return v_;
}

int EdgeWeightedGraph::e() {
    return e_;
}

void EdgeWeightedGraph::addEdge(Edge e) {
    int v = e.either();
    int w = e.other(v);
    adj_[v].push_back(e);
    adj_[w].push_back(e);
}

std::vector<Edge> EdgeWeightedGraph::adj(int v) {
    return adj_[v];
}

std::vector<Edge> EdgeWeightedGraph::edges() {
    return edges_;
}

void EdgeWeightedGraph::toString() {
    for (int i = 0; i < v_; ++i) {
        for (int j = 0; j < adj_[i].size(); ++j) {
            adj_[i][j].toString();
        }
        std::cout << std::endl;
    }
}

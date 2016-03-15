#include "KruskalMST.h"
#include "UF.h"

KruskalMST::KruskalMST(EdgeWeightedGraph &g) {
    std::vector<Edge> edges = g.edges();
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
        pq_.push(*it);
    }
    UF uf(g.v());
    while (!pq_.empty() && mst_.size() < g.v() - 1) {
        Edge e = pq_.top();
        pq_.pop();
        int v = e.either();
        int w = e.other(v);
        if (!uf.connected(v, w)) {
            uf.join(v, w);
            mst_.push_back(e);
            weight_ += e.weight();
        }
    }
}

std::vector<Edge> KruskalMST::edges() {
    return mst_;
}

int KruskalMST::weight() {
    return weight_;
}

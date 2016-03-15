#ifndef EDGE_H
#define EDGE_H
class Edge {
private:
    int v_;
    int w_;
    double weight_;
public:
    Edge();
    Edge(int v, int w, double weight);
    double weight();
    int either();
    int other(int x);
    void toString();
    friend inline bool operator< (const Edge &lhs, const Edge &rhs);
};

inline bool operator< (const Edge &lhs, const Edge &rhs) {
    return lhs.weight_ < rhs.weight_;
}

inline bool operator> (const Edge &lhs, const Edge &rhs) {
    return rhs < lhs;
}

inline bool operator<=(const Edge &lhs, const Edge &rhs) {
    return !(lhs > rhs);
}

inline bool operator>=(const Edge &lhs, const Edge &rhs) {
    return !(lhs < rhs);
}
#endif

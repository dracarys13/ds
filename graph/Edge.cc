#include "Edge.h"
#include <stdio.h>

Edge::Edge(int v, int w, double weight): v_(v), w_(w), weight_(weight) {
}

Edge::Edge() {
}

double Edge::weight() {
    return weight_;
}

int Edge::either() {
    return v_;
}

int Edge::other(int x) {
    if (x == v_) {
        return w_;
    } else if (x == w_) {
        return v_;
    } else {
        return -1;
    }
}

void Edge::toString() {
    printf("%d-%d-%.2f ", v_, w_, weight_);
}

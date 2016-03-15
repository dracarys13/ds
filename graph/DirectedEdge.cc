#include "DirectedEdge.h"
#include <stdio.h>

DirectedEdge::DirectedEdge() {
}

DirectedEdge::DirectedEdge(int from, int to, double weight): from_(from), to_(to), weight_(weight) {
}

void DirectedEdge::toString() {
    printf("%d->%d(%.2f) ", from_, to_, weight_);
}

int DirectedEdge::from() {
    return from_;
}

int DirectedEdge::to() {
    return to_;
}

double DirectedEdge::weight() {
    return weight_;
}

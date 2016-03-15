#include "EdgeWeightedDigraph.h"
#include "DijkstraSP.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./DijkstraSPTest tinyEWD.txt\n");
        exit(1);
    }
    ifstream fin;
    fin.open(argv[1]);
    EdgeWeightedDigraph g(fin);
    g.toString();

    DijkstraSP d(g, 0);
    for (int i = 1; i < g.v(); ++i) {
        std::vector<DirectedEdge> edges = d.pathTo(i);
        printf("to %d:", i);
        for (int j = 0; j < edges.size(); ++j) {
            edges[j].toString();
        }
        printf("\n");
    }
    return 0;
}

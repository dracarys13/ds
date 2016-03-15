#include "EdgeWeightedGraph.h"
#include "KruskalMST.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./LazyPrimMSTTest tinyEWG.txt\n");
        exit(1);
    }
    ifstream fin;
    fin.open(argv[1]);
    EdgeWeightedGraph g(fin);
    g.toString();
    KruskalMST mst(g);
    std::vector<Edge> edges = mst.edges();
    for (int i = 0; i < edges.size(); ++i) {
        edges[i].toString();
        std::cout << std::endl;
    }
    return 0;
}

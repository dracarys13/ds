#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./PrimMSTTest tinyEWG.txt\n");
        exit(1);
    }
    ifstream fin;
    fin.open(argv[1]);
    EdgeWeightedGraph g(fin);
    g.toString();
    PrimMST mst(g);
    std::vector<Edge> edges = mst.edges();
    for (int i = 0; i < edges.size(); ++i) {
        edges[i].toString();
        std::cout << std::endl;
    }
    return 0;
}

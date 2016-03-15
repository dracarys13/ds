#include "EdgeWeightedGraph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./EdgeWeightedGraphTest tinyEWG.txt\n");
        exit(1);
    }
    ifstream fin;
    fin.open(argv[1]);
    EdgeWeightedGraph g(fin);
    g.toString();

    return 0;
}

#include "IndexMinPQ.h"
#include <iostream>

int main() {
    IndexMinPQ<int> pq(10);
    pq.insert(8, -1);
    pq.insert(0, 10);
    pq.insert(1, 1);
    pq.insert(9, 0);
    pq.remove(1);
    pq.removeMin();
    std::cout << "key:" << pq.minKey() << " index:" << pq.minIndex() << std::endl;
}

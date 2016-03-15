#include "UF.h"

UF::UF(int n): count_(n) {
    parent_.assign(n, 0);
    rank_.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        parent_[i] = i;
        rank_[i] = 0;
    }
}

void UF::join(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) {
        return;
    }
    if (rank_[rootp] < rank_[rootq]) {
        parent_[rootp] = rootq;
    } else if (rank_[rootp] > rank_[rootq]) {
        parent_[rootq] = rootp;
    } else {
        parent_[rootq] = rootp;
        rank_[rootp]++;
    }
    --count_;
}

int UF::find(int p) {
    if (p != parent_[p]) {
        parent_[p] = find(parent_[p]);
    }
    return parent_[p];
}

bool UF::connected(int p, int q) {
    return find(p) == find(q);
}

int UF::count() {
    return count_;
}

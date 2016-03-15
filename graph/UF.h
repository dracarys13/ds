#ifndef UF_H
#define UF_H

#include <vector>

class UF {
private:
    std::vector<int> parent_;
    std::vector<int> rank_;
    int count_;
public:
    UF(int n);
    void join(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    int count();
};
#endif

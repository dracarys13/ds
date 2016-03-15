#ifndef INDEXMINPQ_H
#define INDEXMINPQ_H

// reference: http://algs4.cs.princeton.edu/24pq/IndexMinPQ.java.html
#include <vector>

template<class Key>
class IndexMinPQ {
private:
    int max_n_;
    int n_;
    std::vector<int> heap_;  // n_ is heap position, heap_[n_] is index
    std::vector<int> index_;  // i is index, index_[i] is heap position
    std::vector<Key> keys_;  // i is index, keys_[i] is key
public:
    IndexMinPQ(int max_n): max_n_(max_n), n_(0) {
        heap_.resize(max_n + 1);
        index_.assign(max_n + 1, -1);
        keys_.resize(max_n + 1);
    }

    bool empty() {
        return 0 == n_;
    }

    bool contains(int i) {
        if (i < 0 || i >= max_n_) {
            return false;
        }
        return -1 != index_[i];
    }

    int size() {
        return n_;
    }

    void insert(int i, Key key) {
        if (i < 0 || i >= max_n_ || contains(i)) {
            return ;
        }
        ++n_;
        index_[i] = n_;
        heap_[n_] = i;
        keys_[i] = key;
        swim(n_);
    }

    bool less(int i, int j) {
        return keys_[heap_[i]] < keys_[heap_[j]];
    }

    void swap(int i, int j) {
        int tmp = heap_[i];
        heap_[i] = heap_[j];
        heap_[j] = tmp;
        index_[heap_[i]] = i;
        index_[heap_[j]] = j;
    }

    void swim(int k) {
        while (k > 1 && less(k, k / 2)) {
            swap(k, k / 2);
            k = k / 2;
        }
    }

    void sink(int k) {
        while (k * 2 <= n_) {
            int j = 2 * k;
            if (j < n_ && less(j + 1, j)) {
                ++j;
            }
            if (less(k, j)) {
                break;
            }
            swap(k, j);
            k = j;
        }
    }

    void remove(int i) {
        if (i < 0 || i >= max_n_ || !contains(i)) {
            return;
        }
        int heapPos = index_[i];
        swap(heapPos, n_);
        --n_;
        swim(heapPos);
        sink(heapPos);
        index_[i] = -1;
    }

    void removeMin() {
        if (0 == n_) {
            return;
        }
        int indexPos = heap_[1];
        swap(1, n_);
        --n_;
        sink(1);
        index_[indexPos] = -1;
        index_[n_ + 1] = -1;
    }

    int minIndex() {
        return heap_[1];
    }

    Key minKey() {
        return keys_[heap_[1]];
    }
};
#endif

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashFunc.h"
#include <vector>
#include <stdio.h>

template<typename Key, typename Value>
struct Node {
    Key key;
    Value value;
    Node *next;
    Node(Key k, Value v, Node *n): key(k), value(v), next(n) {
    }
};

template<typename Key,
         typename Value = Key,
         typename Hash = hash<Key> >
class HashTable {
private:
    typedef Node<Key, Value> Node_;
    std::vector<Node_ *> buckets_;
    int buckets_num_;
    Hash hash_;
public:
    HashTable(): buckets_num_(97) {
        buckets_.assign(buckets_num_, (Node_ *)0);
    }
    int bucketsIndex(const Key &key) const {
        unsigned int i = hash_(key);
        return (i & 0x7FFFFFFF) % buckets_num_;
    }
    Node_ *find(const Key &key) const {
        int bucket_index = bucketsIndex(key);
        Node_ *first = buckets_[bucket_index];
        while (first) {
            if (first->key == key) {
                return first;
            }
            first = first->next;
        }
        return (Node_ *)0;
    }
    void insert(Key key, Value value) {
        Node_ *node = find(key);
        if (node) {
            node->value = value;
        } else {
            int bucket_index = bucketsIndex(key);
            Node_ *first = buckets_[bucket_index];
            Node_ *node = new Node_(key, value, first);
            buckets_[bucket_index] = node;
        }
    }
    void insert(Key key) {
        insert(key, key);
    }
};
#endif  // HASHTABLE_H

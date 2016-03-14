#ifndef TRIE_H
#define TRIE_H

const int kMax = 26;

struct Node {
    int isstr;
    Node *next[kMax];
};
typedef struct Node Trie;

Trie *createTrie();

void freeTrie(Trie *root);

int insertNode(Trie *root, const char *str);

int findNode(Trie *root, const char *str);

#endif  // TRIE_H

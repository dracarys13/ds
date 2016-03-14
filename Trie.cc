#include "Trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Trie *createTrie() {
    Node *node = (Node *)malloc(sizeof(Node));
    if (NULL == node) {
        printf("initTrie error.\n");
        exit(1);
    }
    node->isstr = 0;
    for (int i = 0; i < kMax; ++i) {
        node->next[i] = NULL;
    }
    return node;
}

void freeTrie(Trie *root) {
    if (NULL == root) {
        return;
    }
    for (int i = 0; i < kMax; ++i) {
        freeTrie(root->next[i]);
    }
    free(root);
}

int insertNode(Trie *root, const char *str) {
    int len = strlen(str);
    if (NULL == root || 0 == len) {
        return 0;
    }
    Trie *ptr = root;
    for (int i = 0; i < len; ++i) {
        if (NULL == ptr->next[str[i] - 'a']) { // does not exist
            Trie *tmp = createTrie();
            ptr->next[str[i] - 'a'] = tmp;
        }
        ptr = ptr->next[str[i] - 'a'];
    }
    ptr->isstr = 1;
    return 1;
}

int findNode(Trie *root, const char *str) {
    int len = strlen(str);
    if (NULL == root || 0 == len) {
        return 0;
    }
    Trie *ptr = root;
    for (int i = 0; i < len; ++i) {
        if (NULL == ptr->next[str[i] - 'a']) {
            return 0;
        }
        ptr = ptr->next[str[i] - 'a'];
    }
    return ptr->isstr;
}

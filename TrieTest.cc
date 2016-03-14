#include "Trie.h"
#include <stdio.h>

int main() {
    Trie *root = createTrie();
    char *strs[] = {"i", "love", "you"};
    int len = sizeof(strs) / sizeof(char *);
    for (int i = 0; i < len; ++i) {
        if (insertNode(root, strs[i])) {
            printf("insert: %s\n", strs[i]);
        } else {
            printf("insert fail: %s\n", strs[i]);
        }
    }

    char *targets[] = {"i", "love", "yov"};
    len = sizeof(targets) / sizeof(char *);
    for (int i = 0; i < len; ++i) {
        if (findNode(root, targets[i])) {
            printf("find: %s\n", targets[i]);
        } else {
            printf("find fail: %s\n", targets[i]);
        }
    }
    return 0;
}

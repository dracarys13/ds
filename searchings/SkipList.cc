#include "SkipList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAXLEVEL) { // todo: need seed
        ++level;
    }
    return level;
}

int less(int key_a, int key_b) {
    return key_a < key_b;
}

int equal(int key_a, int key_b) {
    return key_a == key_b;
}

int less(const char *s1, const char *s2) {
    if (NULL == s1) {
        return 1;
    }
    if (NULL == s2) {
        return 0;
    }
    return strcmp(s1, s2) < 0 ? 1 : 0;
}

int equal(Node *node_a, Node *node_b) {
    return equal(node_a->key, node_b->key);
}

int equal(const char *s1, const char *s2) {
    if (NULL == s1 || NULL == s2) {
        return 0;
    }
    return strcmp(s1, s2) == 0 ? 1 : 0;
}

void printSkipList(SkipList *sl) {
    Node *header = sl->header;
    Node *NIL = header;
    Node *node;
    for (int level = 0; level <= sl->level; ++level) {
        node = header->forward[level];
        while (NIL != node) {
            printf("(%s,%s)->", node->key, node->value);
            node = node->forward[level];
        }
        printf("\n");
    }
}

Node *createNode(int level) {
    Node *node = (Node *)malloc(sizeof(Node) + level * sizeof(Node *));
    if (NULL == node) {
        exit(1);
    }
    memset(node, 0, sizeof(Node) + level * sizeof(Node *));
    return node;
}

SkipList *createSkipList() {
    SkipList *sl = (SkipList *)malloc(sizeof(SkipList));
    if (NULL == sl) {
        exit(1);
    }
    sl->header = createNode(MAXLEVEL);
    sl->level = 0;
    sl->nodeNum = 1;
    Node *header = sl->header;
    Node *NIL = header;
    for (int level = 0; level <= MAXLEVEL; ++level) {
        header->forward[level] = NIL;
    }
    return sl;
}

void destorySkipList(SkipList *sl) {
    Node *node = sl->header;
    for (int i = 0; i < sl->nodeNum; ++i) {
        Node *next = node->forward[0];
        free(node);
        node = next;
    }
    free(sl);
}

SkipList *insert(SkipList *sl, Key key, Value value) {
    Node *header = sl->header;
    Node *NIL = header;
    Node *insertNodes[MAXLEVEL + 1]; // each level's insert position
    Node *node = header;
    // find each level to insert, new node is insert after insertNodes[level].
    for (int level = sl->level; level >= 0; --level) {
        while (NIL != node->forward[level] && less(node->forward[level]->key, key)) {
            node = node->forward[level];
        }
        insertNodes[level] = node;
    }
    node = node->forward[0];
    if (NIL != node && equal(key, node->key)) { // duplicate insert
        return sl;
    }
    int newLevel = randomLevel();
    if (newLevel > sl->level) {
        for (int level = sl->level + 1; level <= newLevel; ++level) {
            insertNodes[level] = NIL;
        }
        sl->level  = newLevel;
    }

    Node *newNode  = createNode(newLevel);
    newNode->key = key;
    newNode->value = value;
    for (int level = 0; level <= newLevel; ++level) {
        newNode->forward[level] = insertNodes[level]->forward[level];
        insertNodes[level]->forward[level] = newNode;
    }
    ++(sl->nodeNum);
    return sl;
}

Node *find(SkipList *sl, Key key) {
    Node *header = sl->header;
    Node *NIL = header;
    Node *node = header;
    for (int level = sl->level; level >= 0; --level) {
        while (NIL != node->forward[level] && less(node->forward[level]->key, key)) {
            node = node->forward[level];
        }
    }
    node = node->forward[0];
    return (NIL != node && equal(node->key, key)) ? node : NULL;
}

void remove(SkipList *sl, Key key) {
    Node *header = sl->header;
    Node *NIL = header;
    Node *node = header;
    Node *removeNodes[MAXLEVEL + 1]; // each level's remove position
    for (int level = sl->level; level >= 0; --level) {
        while (NIL != node->forward[level] && less(node->forward[level]->key, key)) {
            node = node->forward[level];
        }
        removeNodes[level] = node;
    }
    node = node->forward[0];
    if (NIL == node || !equal(node->key, key)) { // no find
        return;
    }
    // until now, node can be removed
    for (int level = 0; level <= sl->level; ++level) {
        if (!equal(removeNodes[level]->forward[level], node)) { // other level does not need remove
            break;
        }
        removeNodes[level]->forward[level] = node->forward[level];
    }

    free(node);
    --(sl->nodeNum);
    while (sl->level > 0 && header->forward[sl->level] == NIL) {
        --(sl->level);
    }
}

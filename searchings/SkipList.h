#ifndef SKIPLIST_H
#define SKIPLIST_H
// reference: https://www.cs.auckland.ac.nz/~jmor159/PLDS210/niemann/s_skl.htm
#include <stdio.h>
#include <stdlib.h>

#define MAXLEVEL 15
typedef char *Key;
typedef char *Value;

//               +---------------------------------+
//               v                                 |
//    sl      header(NIL)                          |
// +------+   +----+    +---+    +---+    +---+    |
// |header+--->key | +-->1  | +-->2  | +-->3  |    |
// +------+   +----+ |  +---+ |  +---+ |  +---+    |
// |      |   |Val | |  |11 | |  |22 | |  |33 |    |
// |      |   +----+ |  +---+ |  +---+ |  +---+    |
// |      |   | |----+  | |---+  | |---+  | |------>
// |      |   +----|    +---| |  +---|    +---|    |
// +------+   | |-------------+  | |---------------+
//            +----+             +---+
//            |    |
//            +----+
//            |    |
//            +----+
//            |    |
//            +----+
//            |    |
//            +----+

typedef struct Node {
    Key key;
    Value value;
    Node *forward[1]; // level is random
} Node;

typedef struct SkipList {
    Node *header;
    int level;
    int nodeNum;
} SkipList;

// some aux function
int randomLevel();

int less(int key_a, int key_b);

int less(const char *s1, const char *s2);

int equal(int key_a, int key_b);

int equal(const char *s1, const char *s2);

int equal(Node *node_a, Node *node_b);

void printSkipList(SkipList *sl);

// Node api
Node *createNode(int level);

// SkipList api
SkipList *createSkipList();

void destorySkipList(SkipList *sl);

SkipList *insert(SkipList *sl, Key key, Value value);

Node *find(SkipList *sl, Key key);

void remove(SkipList *sl, Key key);

#endif // SKIPLIST_H

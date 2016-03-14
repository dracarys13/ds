#include "HashTable.h"
#include <string>
#include <iostream>
using namespace std;


int main() {
    HashTable<std::string, int> wordcount;
    Node<std::string, int> *node;
    wordcount.insert("fuck", 1);
    node = wordcount.find("fuck");
    if (node) {
        cout << node->key << " " << node->value << endl;
    }
    wordcount.insert("fauck", 12);
    node = wordcount.find("fauck");
    if (node) {
        cout << node->key << " " << node->value << endl;
    }
    wordcount.insert("faucka", 13);
    node = wordcount.find("faucka");
    if (node) {
        cout << node->key << " " << node->value << endl;
    }

    return 0;
}

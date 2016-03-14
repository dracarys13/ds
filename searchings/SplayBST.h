#ifndef SPLAYBST_H
#define SPLAYBST_H
#include <stdio.h>
#include <stdexcept>
template<typename Key, typename Value>
class SplayBST {
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key k, Value v): key(k), value(v), left(NULL), right(NULL) {
        }
    };
    Node *root_;
public:
    SplayBST(): root_(NULL) {
    }
    Value get(Key key) {
        root_ = splay(root_, key);
        if (root_->key == key) {
            return root_->value;
        } else {
            throw std::out_of_range("get error");
        }
    }
    void put(Key key, Value value) {
        if (NULL == root_) {
            root_ = new Node(key, value);
            return;
        }
        root_ = splay(root_, key);
        Node *newnode = new Node(key, value);
        if (key < root_->key) {
            newnode->right = root_;
            newnode->left = root_->left;
            root_->left = NULL;
            root_ = newnode;
        } else if (key > root_->key) {
            newnode->left = root_;
            newnode->right = root_->right;
            root_->right = NULL;
            root_ = newnode;
        } else {
            root_->value = value;
        }
    }
    void remove(Key key) {
    }
private:
    Node *splay(Node *root, Key key) {
        if (NULL == root || root->key == key) {
            return root;
        }
        if (key < root->key) {
            if (NULL == root->left) {
                return root;
            }
            if (key < root->left->key) { // left left
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            } else if (key > root->left->key) { // left right
                root->left->right = splay(root->left->right, key);
                if (NULL != root->left->right) {
                    root->left = leftRotate(root->left);
                }
            }
            return (NULL == root->left) ? root : rightRotate(root);
        } else {
            if (NULL == root->right) {
                return root;
            }
            if (key > root->right->key) { // right  right
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            } else if (key < root->right->key) { // right left
                root->right->left = splay(root->right->left, key);
                if (NULL != root->right->left) {
                    root->right = rightRotate(root->right);
                }
            }
            return (NULL == root->right) ? root : leftRotate(root);
        }
    }
    Node *rightRotate(Node *x) {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }
    Node *leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }
};
#endif

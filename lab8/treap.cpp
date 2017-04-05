// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>

// Prototypes - helper functions ------------------------------------------------------------------

extern void dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
    Entry entry = std::make_pair(key, value);
    root = insert_node(root, entry);
    
    
}

const Entry     TreapMap::search(const std::string &key) {
    //TODO
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

int             TreapMap::getMaxTreeHeight(){
    //TODO
}


int             TreapMap::getMinTreeHeight(){
    //TODO
}

void            TreapMap::preOrderTraversal(){
    //TODO
}

// Internal Functions -----------------------------------------------------------------

Node * RotateRight(Node *p) {
    Node *left = p->left;
    Node *subRight = left->right;
    left->right = p;
    p->left = subRight;
    return left;
}

Node * RotateLeft(Node *p) {
    Node *right = p->right;
    Node *subLeft = right->left;
    right->left = p;
    p->right = subLeft;
    return right;
}

int get_random() {
    static random_device rd;
    static default_random_engine g(rd());
    static uniform_int_distributions<> d(1, INT_MAX);
    return d(g);
}

Node * create_node(Entry entry) {
    Node *n;
    n->entry = entry;
    n->priority = get_random();
}

Node *insert_node(Node *root, Entry entry) {
    if (root == NULL) return create_node(entry);

    if (entry.second <= root.entry.second) {

    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

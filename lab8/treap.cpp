// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>

// Prototypes - helper functions ------------------------------------------------------------------

extern void dump_r(Node *node, std::ostream &os, DumpFlag flag);
extern Node *search_r(Node *node, const std::string &key);
Node *RotateRight(Node *node);
Node *RotateLeft(Node *node);
int get_random();
Node* insertTreap_r(Node* root, const std::string &key, const std::string &value);
int findMax_r(Node *node);
int findMin_r(Node *node);
void preOrder_r(Node *node);


// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
    root = insertTreap_r(root, key, value);    
}

const Entry     TreapMap::search(const std::string &key) {
    auto result = search_r(root, key);
    return (result == nullptr ? NONE : result->entry);
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

int             TreapMap::getMaxTreeHeight(){
    return findMax_r(root);   
}


int             TreapMap::getMinTreeHeight(){
    return findMin_r(root);
}

void            TreapMap::preOrderTraversal(){
    preOrder_r(root);
    std::cout << std::endl;
}

// Internal Functions -----------------------------------------------------------------

Node * RotateRight(Node *p) {
    // maintain MaxBinaryHeap property by rotating right
    Node *left = p->left;
    Node *subRight = left->right;
    left->right = p;
    p->left = subRight;
    return left;
}

Node * RotateLeft(Node *p) {
    // rotate node to the left
    Node *right = p->right;
    Node *subLeft = right->left;
    right->left = p;
    p->right = subLeft;
    return right;
}

int get_random() {
    static std::random_device rd;
    static std::default_random_engine g(rd());
    static std::uniform_int_distribution<> d(1, INT_MAX);
    return d(g);
}

Node *insertTreap_r(Node *root, const std::string &key, const std::string &value) {
    if (root == NULL) return new Node{Entry(key, value), get_random(), nullptr, nullptr}; // if given node is NULL, create new node

    if (root->entry.first == key) {
        // update value of node if node with that key already exists
        root->entry.second = value;
        return root;
    }

    if (key <= root->entry.first) {
        root->left = insertTreap_r(root->left, key, value); // recursive call
        if (root->left->priority > root->priority) // rotate if necessary
            root = RotateRight(root);
    }else {
        root->right = insertTreap_r(root->right, key, value);
        if (root->right->priority > root->priority)
            root = RotateLeft(root);
    }

    return root;
}

int findMax_r(Node *node) {
    if (node == NULL) return 0;

    int left_height = findMax_r(node->left);
    int right_height = findMax_r(node->right);

    if (left_height > right_height)
        // compare left and right subtree heights, return highest
        return left_height + 1;
    else
        return right_height + 1;
}

int findMin_r(Node *node) {
    if (node == NULL) return 0;

    int left_height = findMin_r(node->left);
    int right_height = findMax_r(node->right);

    if (left_height < right_height)
        // compare left and right subtree heights, return smaller
        return left_height + 1;
    else
        return right_height + 1;
}

void preOrder_r(Node *node) {
    if (node == NULL) return; // base case

    std::cout << node->entry.second << " "; // print out value

    preOrder_r(node->left); // recursively traverse left subtree
    preOrder_r(node->right); // recursively traverse right subtree
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

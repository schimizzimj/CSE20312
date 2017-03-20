// bst.cpp
// This program reads in input, represents it as a binary tree, and checks whether or not it represents a binary search tree. 
//
// Marcus Schimizzi
// 2/27/17

#include <iostream>
#include<limits.h>
using namespace std;

int checkBST(int tree[], int root, int indexMax, int min, int max); //Recursive function to check all subtrees given the root for BST

int main() {
  int input;
  int count = 1; // used for purposes of keeping track of what test program is on
  bool isBST;
  cin >> input; // read in first value to indicate number of nodes in tree
  while (!cin.eof()) {
    isBST = false; // initialize to be false, recursive function has to prove BST true
    int tree[input]; // create array using number of values needed via first input
    int node;
    for (int i = 0; i < input; i++){
      // iterate through entire line, guided by the first number in the row
      cin >> node;
      tree[i] = node; // read rest of line into array
    }
    isBST = checkBST(tree, 0, input, INT_MIN, INT_MAX); // call recursive function, starting with min and max as the integer min and max
    if (isBST) cout << "Tree " << count << " is a BST" << endl; 
    else cout << "Tree " << count << " is not a BST" << endl;
    count++;
    cin >> input; // read in next input to allow for WHILE loop's conditional check
  }
}

int checkBST(int tree[], int index, int indexMax, int min, int max) {
  // recursive function that checks if array representation of tree represents a BST
  if (tree[index] == -1) return 1; // if value is -1, reached end of line, return true
  if (tree[index] < min || tree[index] > max) return 0; // checks number against min and max

  if ((2*index)+1 >= indexMax) return 1; // check that left child (and right child) is within bounds
  else if ((2*index)+2 >= indexMax) {
    // check if right child is within bounds, if not, check only left subtree
     return checkBST(tree, (2*index) + 1, indexMax, min, tree[index]);
  }else {
    // case if both children are in bounds, checks both subtrees
    return (checkBST(tree, (2*index) + 1, indexMax, min, tree[index]) && checkBST(tree, (2*index) + 2, indexMax, tree[index] + 1, max));
  }

}

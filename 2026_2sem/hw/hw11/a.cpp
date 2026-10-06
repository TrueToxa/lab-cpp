#include <iostream>

struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int key;
};

using std::cout;
using std::endl;

int main() {
  Node* tree = nullptr;
  tree = new Node;
  if ((tree->key == 0) and (tree->left == nullptr) and (tree->right == nullptr) and (tree->parent == nullptr)) {
    cout << "OK" << endl;
  } else {
    cout << endl;
  }
  delete tree;
  return 0;
}
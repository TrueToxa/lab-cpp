#include <iostream>

enum TraverseType { INORDER, PREORDER, POSTORDER };

struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    int key;
};

void insert_node(Node *&tree, int new_key)
{
    if (tree == nullptr)
    {
        Node *new_node = new Node();
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->parent = nullptr;
        new_node->key = new_key;
        tree = new_node;
        return;
    }
    else if (tree->key < new_key)
    {
        insert_node(tree->right, new_key);
        tree->right->parent = tree;
    }
    else
    {
        insert_node(tree->left, new_key);
        tree->left->parent = tree;
    }
    return;
}
void print(Node*& tree, TraverseType type) {
    if (tree == nullptr) {
        std::cout << std::endl;
        return;
    }
    
    if (type == PREORDER) {
        std::cout << tree->key << " ";
        if (tree->left != nullptr) print(tree->left, type);
        if (tree->right != nullptr) print(tree->right, type);
    }
    else if (type == INORDER) {
        if (tree->left != nullptr) print(tree->left, type);
        std::cout << tree->key << " ";
        if (tree->right != nullptr) print(tree->right, type);
    }
    else if (type == POSTORDER) {
        if (tree->left != nullptr) print(tree->left, type);
        if (tree->right != nullptr) print(tree->right, type);
        std::cout << tree->key << " ";
    }
    
    if (tree->parent == nullptr) {
        std::cout << std::endl;
    }
}

using std::cout;
using std::endl;

int main() {
  Node* tree = nullptr;
  insert_node(tree, 4);
  insert_node(tree, 2);
  insert_node(tree, 1);
  insert_node(tree, 3);
  insert_node(tree, 6);
  insert_node(tree, 5);
  insert_node(tree, 7);
  print(tree, TraverseType::INORDER);    // 1 2 3 4 5 6 7
  print(tree, TraverseType::PREORDER);   // 4 2 1 3 6 5 7
  print(tree, TraverseType::POSTORDER);  // 1 3 2 5 7 6 4
  delete tree->left->left;
  delete tree->left->right;
  delete tree->left;
  delete tree->right->left;
  delete tree->right->right;
  delete tree->right;
  delete tree;
  return 0;
}
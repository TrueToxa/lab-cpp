#include <iostream>

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

void destroy_tree(Node *&tree)
{
    if (tree == nullptr)
        return;
    destroy_tree(tree->right);
    destroy_tree(tree->left);
    delete tree;
    tree = nullptr;
}

using std::cout;
using std::endl;

int main()
{
    Node *tree = nullptr;
    insert_node(tree, 4);
    insert_node(tree, 2);
    insert_node(tree, 6);
    destroy_tree(tree);
    if (!(tree)) {
            cout << "OK" << endl;
    }
    return 0;
}
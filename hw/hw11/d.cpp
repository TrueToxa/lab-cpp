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

Node *max(Node *&tree)
{
    if (tree == nullptr)
        return tree;
    if (tree->right == nullptr)
        return tree;
    return max(tree->right);
}

using std::cout;
using std::endl;

int main()
{
    Node *tree = nullptr;
    insert_node(tree, 1);
    insert_node(tree, 2);
    insert_node(tree, 0);
    if (max(tree) == tree->right)
    {
        cout << "OK" << endl;
    }
    delete tree->left;
    delete tree->right;
    delete tree;
    return 0;
}
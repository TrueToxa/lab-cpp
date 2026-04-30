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

Node *find(Node *&tree, int key)
{
    if (tree == nullptr)
        return tree;
    else if (tree->key < key)
        return find(tree->right, key);
    else if (tree->key > key)
        return find(tree->left, key);
    else if (tree->key == key)
        return tree;
    return tree;
}

Node *min_val(Node *node)
{
    if (node == nullptr)
        return nullptr;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void delete_node(Node *&tree, int key)
{
    Node *node = find(tree, key);
    if (node == nullptr)
        return;

    if (node->left != nullptr && node->right != nullptr)
    {
        Node *ans = min_val(node->right);
        node->key = ans->key;
        node = ans;
    }

    Node *child = (node->left != nullptr) ? node->left : node->right;

    if (child != nullptr)
        child->parent = node->parent;

    if (node->parent == nullptr)
        tree = child;
    else if (node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;

    delete node;
}

using std::cout;
using std::endl;

int main()
{
    Node *tree = nullptr;
    insert_node(tree, 4);
    insert_node(tree, 2);
    insert_node(tree, 6);
    delete_node(tree, 3);
    delete_node(tree, 2);
    delete_node(tree, 6);
    if (!(tree->left) && !(tree->right))
    {
        cout << "OK" << endl;
    }
    delete_node(tree, 4);
    return 0;
}
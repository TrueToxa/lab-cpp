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

Node *min(Node *&tree)
{
    if (tree == nullptr)
        return tree;
    if (tree->left == nullptr)
        return tree;
    return min(tree->left);
}

Node *next(Node *&tree, int key)
{
    if (tree == nullptr)
        return tree;
    
    Node *current = find(tree, key);
    if (current == nullptr)
        return nullptr;
    
    if (current->right != nullptr)
    {
        Node *min_next = current->right;
        while (min_next->left != nullptr)
            min_next = min_next->left;
        return min_next;
    }
    
    Node *ans = current->parent;
    while (ans != nullptr && current == ans->right)
    {
        current = ans;
        ans = ans->parent;
    }
    
    return ans;
}
using std::cout;
using std::endl;

int main()
{
    Node *tree = nullptr;
    insert_node(tree, 1);
    insert_node(tree, 2);
    insert_node(tree, 0);
    insert_node(tree, -1);
    if (next(tree, 1) == tree->right and next(tree, -1) == tree->left and next(tree, 2) == nullptr)
    {
        cout << "OK" << endl;
    }
    delete tree->left->left;
    delete tree->left;
    delete tree->right;
    delete tree;
    return 0;
}

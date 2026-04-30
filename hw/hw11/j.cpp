#include <iostream>

using std::cout;
using std::endl;
using std::string;

#include <iostream>
#include <string>

enum Command
{
    BST_INSERT,
    BST_MIN,
    BST_MAX,
    BST_FIND,
    BST_NEXT,
    BST_PRINT,
    BST_DELETE,
    BST_DESTROY,
    BST_FINISH,
    BST_ERR
};

Command get_command(const std::string &cmd)
{
    if (cmd == "insert")
        return BST_INSERT;
    if (cmd == "min")
        return BST_MIN;
    if (cmd == "max")
        return BST_MAX;
    if (cmd == "find")
        return BST_FIND;
    if (cmd == "next")
        return BST_NEXT;
    if (cmd == "print")
        return BST_PRINT;
    if (cmd == "delete")
        return BST_DELETE;
    if (cmd == "destroy")
        return BST_DESTROY;
    if (cmd == "finish")
        return BST_FINISH;
    return BST_ERR;
}

enum TraverseType
{
    INORDER,
    PREORDER,
    POSTORDER
};

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

Node *min(Node *&tree)
{
    if (tree == nullptr)
        return tree;
    if (tree->left == nullptr)
        return tree;
    return min(tree->left);
}

Node *max(Node *&tree)
{
    if (tree == nullptr)
        return tree;
    if (tree->right == nullptr)
        return tree;
    return max(tree->right);
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

void print(Node *&tree, TraverseType type)
{
    if (tree == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    if (type == PREORDER)
    {
        std::cout << tree->key << " ";
        if (tree->left != nullptr)
            print(tree->left, type);
        if (tree->right != nullptr)
            print(tree->right, type);
    }
    else if (type == INORDER)
    {
        if (tree->left != nullptr)
            print(tree->left, type);
        std::cout << tree->key << " ";
        if (tree->right != nullptr)
            print(tree->right, type);
    }
    else if (type == POSTORDER)
    {
        if (tree->left != nullptr)
            print(tree->left, type);
        if (tree->right != nullptr)
            print(tree->right, type);
        std::cout << tree->key << " ";
    }

    if (tree->parent == nullptr)
    {
        std::cout << std::endl;
    }
}

void delete_node(Node *&tree, int key)
{
    Node *node = find(tree, key);
    if (node == nullptr)
        return;

    if (node->left != nullptr && node->right != nullptr)
    {
        Node *ans = min(node->right);
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

void destroy_tree(Node *&tree)
{
    if (tree == nullptr)
        return;
    destroy_tree(tree->right);
    destroy_tree(tree->left);
    delete tree;
    tree = nullptr;
}

int main()
{
    Node *tree = nullptr;
    std::string command;

    while (std::cin >> command)
    {
        Command cmd = get_command(command);

        switch (cmd)
        {
        case BST_INSERT:
        {
            int value;
            std::cin >> value;
            insert_node(tree, value);
            break;
        }
        case BST_MIN:
        {
            Node *result = min(tree);
            if (result != nullptr)
                std::cout << result->key << std::endl;
            break;
        }
        case BST_MAX:
        {
            Node *result = max(tree);
            if (result != nullptr)
                std::cout << result->key << std::endl;
            break;
        }
        case BST_FIND:
        {
            int value;
            std::cin >> value;
            Node *result = find(tree, value);
            if (result != nullptr)
                std::cout << result->key << std::endl;
            break;
        }
        case BST_NEXT:
        {
            int value;
            std::cin >> value;
            Node *result = next(tree, value);
            if (result != nullptr)
                std::cout << result->key << std::endl;
            break;
        }
        case BST_PRINT:
        {
            int type;
            std::cin >> type;
            print(tree, static_cast<TraverseType>(type));
            break;
        }
        case BST_DELETE:
        {
            int value;
            std::cin >> value;
            delete_node(tree, value);
            break;
        }
        case BST_DESTROY:
        {
            destroy_tree(tree);
            tree = nullptr;
            break;
        }
        case BST_FINISH:
        {
            destroy_tree(tree);
            return 0;
        }
        case BST_ERR:
            cout << "ERROR" << endl;
            break;
        }
    }

    destroy_tree(tree);
    return 0;
}
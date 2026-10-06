#include <iostream>

using namespace std;

struct Node
{
    Node *l_child;
    Node *r_child;
    // int key;
    int value;
    int height;
};

Node *insert_node(Node *, int);
int balance_factor(Node *const &root);
int height(Node *const &root);
Node *small_left_totation(Node *pivot);
Node *small_right_totation(Node *pivot);
Node *balance(Node *pivot);

Node *insert_node(Node *pivot, int value)
{
    if (pivot == nullptr)
    {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->r_child = nullptr;
        new_node->l_child = nullptr;
        return new_node;
    }

    if (pivot->value < value)
    {
        pivot->r_child = insert_node(pivot->r_child, value);
    }
    else
    {
        pivot->l_child = insert_node(pivot->l_child, value);
    }
    return balance(pivot);
}

int height(Node *const &root)
{
    if (root == nullptr)
        return 0;
    if (root->r_child == nullptr and root->l_child == nullptr)
    {
        return 1;
    }
    return 1 + max(height(root->r_child), height(root->l_child));
}
int balance_factor(Node *const &root)
{
    return height(root->r_child) - height(root->l_child);
}

Node *small_left_totation(Node *pivot)
{
    Node *new_pivot = pivot->r_child;
    // NOTE We do not change pivot->l_child;
    pivot->r_child = new_pivot->l_child;
    // NOTE We do not change new_pivot->r_child;
    new_pivot->l_child = pivot;
    return new_pivot;
}

Node *small_right_totation(Node *pivot)
{
    Node *new_pivot = pivot->l_child;
    // NOTE We do not change pivot->r_child;
    pivot->l_child = new_pivot->r_child;
    // NOTE We do not change new_pivot->l_child;
    new_pivot->r_child = pivot;
    return new_pivot;
}

void print(Node *const &pivot);
void print(Node *const &pivot)
{
    if (pivot == nullptr)
    {
        return;
    }
    print(pivot->l_child);
    cout << "h=" << height(pivot) << ": v=" << pivot->value << endl;
    print(pivot->r_child);
}
void print_preorder(Node *const &pivot)
{
    if (pivot == nullptr)
    {
        return;
    }
    cout << "h=" << height(pivot) << ": v=" << pivot->value << endl;
    print_preorder(pivot->l_child);
    print_preorder(pivot->r_child);
}
void print_postorder(Node *const &pivot)
{
    if (pivot == nullptr)
    {
        return;
    }
    print_postorder(pivot->l_child);
    print_postorder(pivot->r_child);
    cout << "h=" << height(pivot) << ": v=" << pivot->value << endl;
}

Node *balance(Node *pivot)
{
    if (balance_factor(pivot) == 2)
    {
        if (balance_factor(pivot->r_child) < 0)
        {
            pivot->r_child = small_right_totation(pivot->r_child);
        }
        return small_left_totation(pivot);
    }
    if (balance_factor(pivot) == -2)
    {
        if (balance_factor(pivot->l_child) < 0)
        {
            pivot->l_child = small_left_totation(pivot->l_child);
        }
        return small_right_totation(pivot);
    }
    return pivot;
}

int main()
{
    Node *root = new Node();
    root->value = 0;
    root->r_child = nullptr;
    root->l_child = nullptr;
    root = insert_node(root, 1 /*value*/);
    cout << height(root) << endl;
    root = insert_node(root, 2 /*value*/);
    cout << height(root) << endl;
    root = insert_node(root, 3 /*value*/);
    cout << height(root) << endl;
    root = insert_node(root, 4 /*value*/);
    cout << height(root) << endl;
    root = insert_node(root, 5 /*value*/);
    cout << height(root) << endl;
    root = insert_node(root, 6 /*value*/);
    cout << height(root) << endl;

    print_preorder(root);
    cout << endl;
    print(root);
    cout << endl;
    print_postorder(root);
    
    // root = small_left_totation(root);
    // cout << endl;
    // print(root);
    // root = small_left_totation(root);
    // cout << endl;
    // print(root);
    // root = small_left_totation(root);
    // cout << endl;
    // print(root);
}

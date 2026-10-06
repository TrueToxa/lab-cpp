#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Node
{
    string name;
    Node *next;
};

void push_back(Node *&head_ref, string new_name)
{
    if (head_ref == nullptr)
    {
        head_ref = new Node();
        head_ref->name = new_name;
        head_ref->next = head_ref;
        return;
    }

    Node *current = head_ref;
    while (current->next != head_ref)
    {
        current = current->next;
    }

    Node *tail = new Node();
    tail->name = new_name;
    tail->next = head_ref;
    current->next = tail;
}

int main()
{
    int N;
    cin >> N;

    Node *HEAD = nullptr;

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        push_back(HEAD, name);
    }

    int k;
    cin >> k;

    string target;
    cin >> target;

    Node *current = HEAD;
    Node *prev = nullptr;

    while (current->next != current)
    {
        for (int i = 1; i < k; i++)
        {
            prev = current;
            current = current->next;
        }

        if (current->name == target)
        {
            static int round = 1;
            cout << round << endl;
            return 0;
        }

        if (current == HEAD)
        {
            Node *tmp = HEAD;
            while (tmp->next != HEAD)
                tmp = tmp->next;
            HEAD = HEAD->next;
            tmp->next = HEAD;
            delete current;
            current = HEAD;
            prev = tmp;
        }
        else
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }

        static int round = 1;
        round++;
    }

    if (current->name == target)
    {
        static int round = 1;
        cout << round << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

struct Node{
    long long key;
    Node* next;
};

void push_front(Node*& head_ref, long long new_data) {
    if (head_ref == nullptr) {
        head_ref = new Node();
        head_ref->key = new_data;
        head_ref->next = nullptr;
        return;
    }
    Node *head = new Node();
    head->key = new_data;
    head->next = head_ref;
    head_ref = head;
}

long long pop(Node*& head_ref) {
    long long val = head_ref->key;
    Node* tmp = head_ref;
    head_ref = head_ref->next;
    delete tmp;
    return val;
}

int main()
{
    std::vector<std::string> tokens;
    std::string token;
    while (true)
    {
        std::getline(std::cin, token, ' ');
        if (token == "stop")
            break;
        if (token.empty())
            continue;
        tokens.push_back(token);
    }

    Node* HEAD = nullptr;
    for (int i = tokens.size() - 1; i >= 0; --i) {
        const std::string& t = tokens[i];
        if (t == "+") {
            long long a = pop(HEAD);
            long long b = pop(HEAD);
            push_front(HEAD, a + b);
        } else if (t == "*") {
            long long a = pop(HEAD);
            long long b = pop(HEAD);
            push_front(HEAD, a * b);
        } else {
            push_front(HEAD, std::stoll(t));
        }
    }

    std::cout << HEAD->key << std::endl;

    return 0;
}
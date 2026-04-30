#include <iostream>

struct Node{
    int key;
    Node* next;
};
void push_back(Node*& head_ref, int new_data) {
    if (head_ref==nullptr) {
        head_ref = new Node();
        head_ref->key = new_data;
        head_ref->next = nullptr;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node* tail = new Node();
    tail->key = new_data;
    tail->next = nullptr;
    current->next = tail;
}
void destroy_list(Node*& head_ref) {
    while (head_ref != nullptr) {
        Node* curr_tmp = head_ref;
        head_ref = head_ref->next;
        delete curr_tmp;
    }
    
}
Node* find(Node* head_ref, int key) {
    for (Node* current = head_ref; current!=nullptr; current = current->next) {
        if (current->key == key) {
            return current;
        }
    }
    return nullptr;
}


using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr, *current = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  current = find(HEAD, 2);
  if (current->key == 2) {
    cout << "OK" << endl;
  }
  return 0;
}
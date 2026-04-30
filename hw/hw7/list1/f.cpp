#include <iostream>
using std::cout;
using std::endl;

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
void print_list(Node* head_ptr) {
    for (Node *current = head_ptr; current!=nullptr; current = current->next)
        {
            if (current == head_ptr) {
                cout << current->key;
            } else {
                cout << ' ' << current->key;
            }
        }
        cout << endl;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  print_list(HEAD);
  destroy_list(HEAD);
  return 0;
}
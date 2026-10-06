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
void remove_key(Node*& head_ref, int key) {
    if (head_ref==nullptr) {
        return;
    }
    if (head_ref->key == key) {
                Node* tmp = head_ref;
                head_ref = head_ref->next;
                delete tmp;
                return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        if (current->next->key == key) {
            Node *tmp = current->next;
            current->next = current->next->next;
            delete tmp;
            return;
        }
        current = current->next;
    }
    return;
}


int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  remove_key(HEAD, 0);
  remove_key(HEAD, 1);
  remove_key(HEAD, 2);
  remove_key(HEAD, 3);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}

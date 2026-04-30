#include <iostream>

struct Node{
    int key;
    Node* next;
};
// и функции void push_front(Node*& head_ref, int new_data)
void push_front(Node*& head_ref, int new_data) {
    if (head_ref==nullptr) {
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

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_front(HEAD, 2);
  push_front(HEAD, 1);
  push_front(HEAD, 0);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}
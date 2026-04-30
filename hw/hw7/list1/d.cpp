#include <iostream>

struct Node{
    int key;
    Node* next;
};

void insert_after(Node*& prev_ref, int new_key) {
    Node* midle = new Node();
    midle->next = prev_ref->next;
    midle->key = new_key;
    prev_ref->next = midle;

}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = new Node;
  insert_after(HEAD, 0);
  insert_after(HEAD, 1);
  insert_after(HEAD, 2);
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
#include <iostream>

struct Node {
    Node *prev = nullptr;
    Node *next = nullptr;
    int key = 0;
};
struct List {
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL  = nullptr;
    size_t size = 0;
};

List* create_empty_list() {
    List* new_list = new List();
    new_list->NIL = new Node();
    new_list->NIL->next = nullptr;
    new_list->HEAD = new_list->NIL;
    new_list->TAIL = new_list->NIL;
    return new_list;
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  if ((list->HEAD == list->NIL) and (list->TAIL == list->NIL) and (list->NIL != nullptr)) {
    cout << "OK" << endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}
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

List* push_back(List* list_ptr, int new_key) {
    if (list_ptr == nullptr) {
        return nullptr;
    }

    if (list_ptr->TAIL == list_ptr->NIL) {
        list_ptr->TAIL = new Node();
        list_ptr->TAIL->key = new_key;
        list_ptr->TAIL->prev = list_ptr->NIL;
        list_ptr->TAIL->next = list_ptr->NIL; 
        list_ptr->HEAD = list_ptr->TAIL;
        list_ptr->size++;
    }
    else {
        Node* new_TAIL = new Node();
        new_TAIL->key = new_key;
        new_TAIL->prev = list_ptr->TAIL;
        new_TAIL->next = list_ptr->NIL;
        list_ptr->TAIL->next = new_TAIL;
        list_ptr->TAIL = new_TAIL;
        list_ptr->size++;
    }
    
    return list_ptr;
}

using std::cout;
using std::endl;

void print_list(const List* list_ptr) {
    if (list_ptr == nullptr) {
        cout << endl;
        return;
    }
    
    Node* current = list_ptr->HEAD;
    
    while (current != list_ptr->NIL) {
        if (current == list_ptr->HEAD) {
            cout << current->key;
        } else {
            cout << ' ' << current->key;
        }
        current = current->next;
    }
    cout << endl;
}


int main() {
  List* list = create_empty_list();
  list = push_back(list, 1);
  list = push_back(list, 2);
  list = push_back(list, 3);
  print_list(list);
  delete list->HEAD;
  delete list->NIL;
  delete list;
  return 0;
}

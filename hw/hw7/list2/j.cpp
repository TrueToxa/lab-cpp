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

void destroy_list(List* list_ptr) {
    /*устрой дестрой - порядок это отстой*/
        if (list_ptr == nullptr) {
        return;
    }
    
    while (list_ptr->HEAD != list_ptr->NIL) {
        Node* curr_tmp = list_ptr->HEAD;
        list_ptr->HEAD = list_ptr->HEAD->next;
        delete curr_tmp;
    }
    delete list_ptr->NIL;
    delete list_ptr;
}
Node* find_key(List* list_ptr, int key) {
    if (list_ptr == nullptr) {
        return nullptr;
    }
    
    Node* current = list_ptr->HEAD;
    
    while (current != list_ptr->NIL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return list_ptr->NIL;
}

using std::cout;
using std::endl;

int main() {
  List* list = create_empty_list();
  Node* ptr = nullptr;
  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  ptr = find_key(list, 2);
  if (ptr == list->TAIL) {
    cout << "OK" << endl;
  }
  destroy_list(list);
  return 0;
}
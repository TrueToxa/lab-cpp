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
/********************/
List* insert_after(List* list_ptr, Node* prev_ptr, int new_key) {
    // NaN
    if (list_ptr == nullptr || prev_ptr == nullptr) {
        return nullptr;
    } 
    // empty
    else if (list_ptr->TAIL == list_ptr->NIL) {
        list_ptr->TAIL = new Node();
        list_ptr->TAIL->key = new_key;
        list_ptr->TAIL->prev = list_ptr->NIL;
        list_ptr->TAIL->next = list_ptr->NIL; 
        list_ptr->HEAD = list_ptr->TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    // after NIL
    else if (prev_ptr == list_ptr->NIL) {
        Node* new_HEAD = new Node();
        new_HEAD->key = new_key;
        new_HEAD->prev = list_ptr->NIL;
        new_HEAD->next = list_ptr->HEAD;
        list_ptr->HEAD->prev = new_HEAD;
        list_ptr->HEAD = new_HEAD;
        list_ptr->size++;
        return list_ptr;
    }
    // after TAIL
    else if (prev_ptr == list_ptr->TAIL) {
        Node* new_TAIL = new Node();
        new_TAIL->key = new_key;\
        new_TAIL->next = list_ptr->NIL;
        new_TAIL->prev = prev_ptr;
        prev_ptr->next = new_TAIL;
        list_ptr->TAIL = new_TAIL;
        list_ptr->size++;
        return list_ptr;
    }
    // full in midle
    else {
        Node* middle = new Node();
        middle->key = new_key;
        middle->next = prev_ptr->next;
        prev_ptr->next->prev = middle;
        middle->prev = prev_ptr;
        prev_ptr->next = middle;
        list_ptr->size++;
        return list_ptr;
    }

}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  list = insert_after(list, list->HEAD, 1);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->TAIL;
  delete list->NIL;
  delete list;
  return 0;
}

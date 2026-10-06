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
void remove_key(List* list_ptr, int key) {
    if (list_ptr == nullptr) {
        return;
    }
    
    Node* current = list_ptr->HEAD;
    
    while (current != list_ptr->NIL) {
        if (current->key == key) {
            if (current == list_ptr->HEAD) {
                list_ptr->HEAD = list_ptr->HEAD->next;
                if (list_ptr->HEAD != list_ptr->NIL) {
                    list_ptr->HEAD->prev = list_ptr->NIL;
                }
                delete current;
                list_ptr->size--;
                current = list_ptr->HEAD;
            }
            else if (current == list_ptr->TAIL) {
                list_ptr->TAIL = list_ptr->TAIL->prev;
                list_ptr->TAIL->next = list_ptr->NIL;
                delete current;
                list_ptr->size--;
                current = list_ptr->NIL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                Node* temp = current->next;
                delete current;
                list_ptr->size--;
                current = temp;
            }
            return;
        }
        current = current->next;
    }
}
using std::cout;
using std::endl;

int main() {
  List* list = create_empty_list();
  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  remove_key(list, 2);
  if (list->TAIL->key == 1) {
    cout << "OK" << endl;
  }
  return 0;
}

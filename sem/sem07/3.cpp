#include <iostream> 
using std::cout;
using std::endl;

struct Node {
    int field;
    Node *next;
};
/*
Краевые случаи
1. Пустой массив
2. 1 элемент
*/
/*
void front_push(Node** HEAD, int value) {
    if (*HEAD == nullptr) {
        *HEAD = new Node();
        *HEAD->field = value;
        *HEAD->next = nullptr;
        return;
    }

    Node *new_HEAD = new Node();
    new_HEAD->field = value;
    new_HEAD->next = HEAD;
}
*/

struct List {
    Node *HEAD;
    Node *TAIL;
    Node *NIL;
};

List *create_list() {
    List *list = new List();
    list->HEAD = nullptr;
    list->TAIL = nullptr;
    list->NIL = new Node();
    list->NIL = nullptr;
}

void front_push(Node*& list, int value) {
    if (list->HEAD == nullptr) {
        list->HEAD = new Node();
        list->HEAD->field = value;
        list->HEAD->next = nullptr;
        return;
    }

    Node *new_HEAD = new Node();
    new_HEAD->field = value;
    new_HEAD->next = HEAD;
    list->HEAD = new_HEAD;
}

int main(){
    {
        List *list = create_list();
        front_push(list, 0);
        cout << list->HEAD->field << endl;
    }
    {
        Node *HEAD = nullptr;
        front_push(list, 0);
        front_push(list, -1);
        front_push(list, -2);
        for (Node *current = list->HEAD; current!=list->NIL; current = current->next)
        {
            cout << current->field << endl;
        }
        
    }

    return 0;
}

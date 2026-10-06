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
void front_push(Node* &HEAD, int value) {
    if (HEAD == nullptr) {
        HEAD = new Node();
        HEAD->field = value;
        HEAD->next = nullptr;
        return;
    }

    Node *new_HEAD = new Node();
    new_HEAD->field = value;
    new_HEAD->next = HEAD;
    HEAD = new_HEAD;
}

struct List {cu
    Node *HEAD;
    Node *TAIL;
    Node *NIL;
};

List *create_list() {
    List *list = new List();
    list->HEAD = nullptr;
    list->TAIL = nullptr;
    list->NIL = new Node();
    list->NIL-> = nullptr;
}

int main(){
    {
        Node *HEAD = nullptr;
        front_push(HEAD, 0);
        front_push(HEAD, -1);
        front_push(HEAD, -2);
        for (Node *current = HEAD; current!=nullptr; current = current->next)
        {
            cout << current->field << endl;
        }
        
    }

    return 0;
}

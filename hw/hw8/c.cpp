

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node {
  int key;
  Node* next;
};

// Где-то тут определены
void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

void destroy_list(Node*& head) {
    while (head != nullptr) {
        Node* curr_tmp = head;
        head = head->next;
        delete curr_tmp;
    }
}

// Место для реализации функций
void push_back(Node*& head_ref, int new_key) {
    if (head_ref==nullptr) {
        head_ref = new Node();
        head_ref->key = new_key;
        head_ref->next = nullptr;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    Node* tail = new Node();
    tail->key = new_key;
    tail->next = nullptr;
    current->next = tail;
}

Node* read_list(Node* head) {
    int input;
    cin >> input;
    while (input !=0) {
        push_back(head, input);\
        cin >> input;
    }
    push_back(head, input);\
    return head;
}

Node* reverse(Node* head) {
    Node* prev_ptr = nullptr;
    Node* ptr = head;
    while (ptr!=nullptr) {
        Node* tmp = ptr;
        ptr = ptr->next;
        tmp->next = prev_ptr;
        prev_ptr = tmp;
    }
    return prev_ptr;
}

int find_middle(const Node* head) {
    int k = 2;
    const Node* half_ptr = head;
    const Node* current_ptr = head;
    while (current_ptr!=nullptr) {
        
        current_ptr = current_ptr->next;
        if (current_ptr==nullptr) {
            // cout << '*' << endl;
            return half_ptr->key;
        }
        current_ptr = current_ptr->next;
        half_ptr = half_ptr->next;
    }
    return half_ptr->key;
}

Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1==nullptr) return list2;
    if (list2==nullptr) return list1;
    Node* new_list = nullptr;
    if (list1->key <= list2->key) {
        new_list = list1;
        list1 = list1->next;
    } else {
        new_list = list2;
        list2 = list2->next;
    }
    Node* current = new_list;
    while (list1 != nullptr && list2!= nullptr) {
        if (list1->key <= list2->key) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1==nullptr) current->next = list2;
    else current->next = list1;
    return new_list;
}
// Принципиальный вид main
int main() {
    Node* head = nullptr;
    head = read_list(head);
    //   head = reverse(head);
    cout << find_middle(head) << endl; 
    // print_list(head);
    destroy_list(head);
    return 0;
}
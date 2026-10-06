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

// void push_front(Node*& head_ref, int new_data) {
//     if (head_ref==nullptr) {
//         head_ref = new Node();
//         head_ref->key = new_data;
//         head_ref->next = nullptr;
//         return;
//     }
//     Node *head = new Node();
//     head->key = new_data;
//     head->next = head_ref;
//     head_ref = head;
// }

// Node* reverse(Node* head) {
//     Node* new_head = nullptr;
//     Node* ptr = head;
//     while (ptr!=nullptr) {
//         push_front(new_head, ptr->key);
//         ptr = ptr->next;
//     }
//     return new_head;
// }

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
    Node* half_ptr = head;
    Node* current_ptr = head;
    while (current_ptr!=nullptr) {
        half_ptr = half_ptr->next;
        for (int i=1, i<= k, i++) {
            current_ptr = current_ptr->next;
        }
    }
    return half_ptr;
}

// Принципиальный вид main
int main() {
  Node* head = nullptr;
  head = read_list(head);
  head = reverse(head);
  print_list(head);
  destroy_list(head);
  return 0;
}
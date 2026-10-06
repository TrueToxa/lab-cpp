#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *curr = head;
    if (curr == nullptr)
    {
        return curr;
    }
    int sum = curr->val;
    ListNode *new_head = nullptr;
    while (curr->next != nullptr)
    {
        if (sum == 0)
        {
            //была ошибка, из-за которой я переписал тестирование
            // ListNode *new_head = curr->next;
            new_head = curr->next;
            break;
        }
        curr = curr->next;
        sum += curr->val;
    }
    if (new_head == nullptr)
    {
        head->next = removeZeroSumSublists(head->next);
        return head;
    }
    // удаляем все элементы от head до new_head
    curr = head;
    while (curr->next != new_head)
    {
        ListNode *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    return removeZeroSumSublists(new_head);
}

void print_arr(ListNode* head) {
    ListNode *curr = head;
    if (curr == nullptr)
    {
        return;
    }
    while (curr->next != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << curr->val << endl;
}

void add(ListNode* head, int key) {
    ListNode *curr = head;
    if (curr == nullptr)
    {
        return;
    }
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    ListNode *tail = new ListNode();
    tail->val = key;
    tail->next = nullptr;
    curr->next = tail;
    return;
}

int main() {
    ListNode *head = new ListNode();
    // [1,2,-3,3,1]
    head->val = 1;
    add(head, 2);
    add(head, -3);
    add(head, 3);
    add(head, 1);
    print_arr(head);
    //работает
    print_arr(removeZeroSumSublists(head));
    return 1;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* removeZeroSumSublists(ListNode* head) {\
        ListNode* curr = head;
        if (curr == nullptr) {
            return curr;
        }
        int sum = curr->val;
        ListNode* new_head = nullptr;
        while (curr->next!=nullptr) {
            if (sum == 0) {
                ListNode* new_head = curr->next;
                break;
            }
            curr = curr->next;
            sum += curr->val;
        }
        if (new_head == nullptr) {
            return head;
        }
        // удаляем все элементы от head до new_head
        curr = head;
        while (curr->next!=new_head) {
            ListNode* tmp = curr;
            curr = curr->next;
            delete tmp;
        }

        // дальше вызываем рекурсивно 
        removeZeroSumSublists(new_head);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode* curr = head;
    if (curr == nullptr_t) {
        return curr;
    }
    int sum = curr->val;
    struct ListNode* new_head = nullptr_t;
    while (curr->next!=nullptr_t) {
        if (sum == 0) {
            ListNode* new_head = curr->next;
            break;
        }
        curr = curr->next;
        sum += curr->val;
    }
    if (new_head == nullptr_t) {
        head->next = removeZeroSumSublists(head->next)
        return head;;
    }
    // удаляем все элементы от head до new_head
    curr = head;
    while (curr->next!=new_head) {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    // дальше вызываем рекурсивно 
    return removeZeroSumSublists(new_head);
}
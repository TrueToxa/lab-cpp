Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1==nullptr) return list2;
    if (list2==nullptr) return list1;
    Node* new_list = nullptr;
    if (list1->data <= list2->data) {
        new_list = list1;
        list1 = list1->next;
    } else {
        new_list = list2;
        list2 = list2->next;
    }
    Node* current = new_list;
    while (list1 != nullptr && list2!= nullptr) {
        if (list1->data <= list2->data) {
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
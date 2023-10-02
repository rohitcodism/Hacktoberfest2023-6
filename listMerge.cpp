// linkedlist merge in cpp

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists.
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node to simplify merging logic.
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If one list is exhausted, connect the remaining part of the other list.
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    // Return the merged list (skip the dummy node).
    ListNode* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

// Function to print a linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create two sorted linked lists.
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    std::cout << "List 1: ";
    printList(l1);

    std::cout << "List 2: ";
    printList(l2);

    // Merge the two sorted linked lists.
    ListNode* merged = mergeTwoLists(l1, l2);

    std::cout << "Merged List: ";
    printList(merged);

    // Clean up memory (free allocated nodes).
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}

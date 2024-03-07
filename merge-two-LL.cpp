#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0); // dummy node to facilitate merging
        ListNode* temp = dummy; // pointer to track the current position in the merged list
        
        // Merge the lists while both of them are not empty
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        // Append remaining nodes from list1 or list2, if any
        if (list1) {
            temp->next = list1;
        }
        if (list2) {
            temp->next = list2;
        }
        
        temp = dummy->next; // Assign the head of the merged list to temp
        delete dummy; // Delete the dummy node
        return temp; // Return the head of the merged list
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Creating two sorted linked lists: 1 -> 2 -> 4 and 1 -> 3 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Printing the merged list
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}

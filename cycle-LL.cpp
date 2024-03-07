#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
        // till fast and fast-> next not reaches NULL
        // we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            // At the point if fast and slow are at same address
            // this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
        // if traversal reaches to NULL this means no cycle.
        return false;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    // Printing the linked list
    cout << "Linked list: ";
    printList(head);

    // Checking if the linked list has a cycle
    Solution solution;
    bool hasCycle = solution.hasCycle(head);

    if (hasCycle) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}

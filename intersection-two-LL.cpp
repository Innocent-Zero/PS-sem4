#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> st;
        
        // Insert nodes from list A into the set
        while (headA != nullptr) {
            st.insert(headA);
            headA = headA->next;
        }
        
        // Traverse list B and check if any node exists in the set
        while (headB != nullptr) {
            if (st.find(headB) != st.end()) {
                return headB; // Intersection node found
            }
            headB = headB->next;
        }
        
        return nullptr; // No intersection node found
    }
};

int main() {
    // Creating two linked lists
    ListNode* commonNode = new ListNode(8);
    commonNode->next = new ListNode(4);
    commonNode->next->next = new ListNode(5);

    ListNode* listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = commonNode;

    ListNode* listB = new ListNode(5);
    listB->next = new ListNode(0);
    listB->next->next = new ListNode(1);
    listB->next->next->next = commonNode;

    Solution solution;
    ListNode* intersectionNode = solution.getIntersectionNode(listA, listB);

    // Output the intersection node value (or nullptr if no intersection)
    if (intersectionNode) {
        cout << "Intersection Node Value: " << intersectionNode->val << endl;
    } else {
        cout << "No Intersection Found" << endl;
    }

    return 0;
}

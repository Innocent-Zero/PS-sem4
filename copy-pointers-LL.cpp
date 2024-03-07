#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> old_to_new;
        
        // Create copies of each node and store the mapping between original and copied nodes
        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Update next and random pointers of copied nodes
        curr = head;
        while (curr) {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }
        
        // Return the head of the copied list
        return old_to_new[head];
    }
};

// Function to print the linked list with random pointers
void printListWithRandom(Node* head) {
    Node* current = head;
    while (current) {
        cout << "Node val: " << current->val;
        if (current->random) {
            cout << ", Random pointer: " << current->random->val;
        } else {
            cout << ", Random pointer: nullptr";
        }
        cout << endl;
        current = current->next;
    }
}

int main() {
    // Creating the original linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    head->random = head->next->next; // Random pointer of node 1 points to node 3
    head->next->random = head;       // Random pointer of node 2 points to node 1
    head->next->next->random = head->next; // Random pointer of node 3 points to node 2
    
    // Creating a solution object and copying the original linked list
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);
    
    // Printing the copied linked list with random pointers
    cout << "Copied linked list with random pointers:" << endl;
    printListWithRandom(copiedList);
    
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1, s2;

public:
    void push(int x) {
        // Push the new element onto s1
        s1.push(x);
    }

    int pop() {
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // Pop the front element from s2
        int front_element = s2.top();
        s2.pop();
        return front_element;
    }

    int peek() {
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // Return the front element of s2
        return s2.top();
    }

    bool empty() {
        // Both stacks are empty if and only if the queue is empty
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);

    cout << "Front element: " << queue.peek() << endl;
    cout << "Pop: " << queue.pop() << endl;
    cout << "Empty: " << (queue.empty() ? "true" : "false") << endl;

    return 0;
}

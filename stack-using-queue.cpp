#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Push the new element to q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);

    cout << "Top element: " << stack.top() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Empty: " << (stack.empty() ? "true" : "false") << endl;

    return 0;
}

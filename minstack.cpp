#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> s, minIdx;
public:
    void push(int val) {
        if(minIdx.empty() || val < s[minIdx.back()]) minIdx.push_back(s.size());
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        if(!minIdx.empty() && minIdx.back() == s.size()) minIdx.pop_back();
    }

    int top() { return s.back(); }
    int getMin() { return s[minIdx.back()]; }
};

int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum element in the stack: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Top element in the stack after pop: " << minStack.top() << endl;
    cout << "Minimum element in the stack after pop: " << minStack.getMin() << endl;

    return 0;
}

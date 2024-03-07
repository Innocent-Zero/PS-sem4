#include <iostream>
#include <vector>

using namespace std;

class MaxStack {
    vector<int> s, maxIdx;
public:
    void push(int val) {
        if(maxIdx.empty() || val > s[maxIdx.back()]) maxIdx.push_back(s.size());
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        if(!maxIdx.empty() && maxIdx.back() == s.size()) maxIdx.pop_back();
    }

    int top() { return s.back(); }
    int getMax() { return s[maxIdx.back()]; }
};

int main() {
    MaxStack maxStack;
    
    maxStack.push(3);
    maxStack.push(1);
    maxStack.push(5);

    cout << "Maximum element in the stack: " << maxStack.getMax() << endl;

    maxStack.pop();
    cout << "Top element in the stack after pop: " << maxStack.top() << endl;
    cout << "Maximum element in the stack after pop: " << maxStack.getMax() << endl;

    return 0;
}

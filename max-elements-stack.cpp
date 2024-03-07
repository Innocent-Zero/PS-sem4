#include <bits/stdc++.h>
using namespace std;

class StackWithMax
{
    stack<int> mainStack;
    stack<int> trackStack;

public:
    void push(int x)
    {
        mainStack.push(x);
        if (mainStack.size() == 1)
        {
            trackStack.push(x);
            return;
        }
        if (x > trackStack.top())
            trackStack.push(x);
        else
            trackStack.push(trackStack.top());
    }

    int getMax()
    {
        return trackStack.top();
    }

    void pop()
    {
        mainStack.pop();
        trackStack.pop();
    }
};

int main()
{
    StackWithMax s;
    s.push(20);
    cout << s.getMax() << endl;
    s.push(10);
    cout << s.getMax() << endl;
    s.push(50);
    cout << s.getMax() << endl;
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

// approach :
// we are using an aux stack
// push x in stack
// push op: if s.top is smaller or equal to the aux.top,then push x to aux stack also
// in this way, the aux stack will always have the smallest ele on the top
// pop op: if s.top and aux.top are same, then pop from both the arrays
// getMin op: simply returning the aux.top will give us min ele in O(1) time

struct myStack
{
    stack<int>s;
    stack<int>aux;
    void push(int x)
    {
        s.push(x);
        if(aux.empty())
        aux.push(x);
        if(s.top()<=aux.top())
        aux.push(x);
    }
    void pop()
    {
        if(s.empty())
        return;
        if(s.top()==aux.top())
        aux.pop();
        s.pop();
    }
    void getMin()
    {
        cout<<aux.top()<<endl;
    }
};

int main()
{
    myStack s;
    s.push(20);
    s.push(7);
    s.push(16);
    s.push(11);
    s.push(5);
    s.push(12);
    s.pop();
    s.pop();
    s.getMin();
    return 0;
}
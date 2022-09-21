#include <iostream>
using namespace std;

struct stack
{
    int cap;
    int pointer;
    int *arr;

    stack(int c)
    {
        cap = c;
        pointer = -1;
        arr = new int[c];
    }

    void push(int x)
    {
        if(pointer + 1 == cap)
        return;
        pointer++;
        arr[pointer] = x;
    }

    void pop()
    {
        if(pointer == -1)
        return;
        pointer--;
    }

    int top()
    {
        if(pointer == -1)
        return INT_MAX;
        return arr[pointer];
    }

    bool empty()
    {
        return (pointer == -1);
    }

    int size()
    {
        return pointer + 1;
    }
};

int main()
{
    stack s(5);
    cout<<s.empty()<<endl;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(2);
    cout<<s.size()<<" "<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.size()<<" "<<s.top()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}
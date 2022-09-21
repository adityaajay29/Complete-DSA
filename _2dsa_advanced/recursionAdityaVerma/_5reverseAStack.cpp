#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int &top)
{
    if(s.empty())
    {
        s.push(top);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s, top);
    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if(s.empty())
    return;
    int top=s.top();
    s.pop();
    reverseStack(s);
    insert(s,top);
}

int main()
{
    int n,a;
    stack<int> s;
    cin>>n;
    while(n--)
    {
        cin>>a;
        s.push(a);
    }
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int getMin(stack<int>s)
{
    if(s.empty())
    return -1;
    int res=s.top();
    s.pop();
    while(!s.empty())
    {
        res=min(res,s.top());
        s.pop();
    }
    return res;
}

int main()
{
    stack<int>s;
    s.push(20);
    s.push(7);
    s.push(16);
    s.push(11);
    s.push(12);
    cout<<getMin(s)<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
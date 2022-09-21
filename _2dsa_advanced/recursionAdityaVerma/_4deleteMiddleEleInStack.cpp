#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int> &s)
{
    static int mid=s.size()/2;
    if(s.size() == 0)
    return;
    if(s.size() == mid+1)
    {
        s.pop();
        return;
    }
    int temp= s.top();
    s.pop();
    deleteMid(s);
    s.push(temp);
}

int main()
{
    int n,a;
    cin>>n;
    stack<int> s;
    while(n--)
    {
        cin>>a;
        s.push(a);
    }
    deleteMid(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

// TC : O(n)
// SC : (n)

void insert(stack<int> &s, int &temp)
{
    // if no ele in stack or stack is already sorted, push temp
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    // else pop the top until stack is sorted or empty
    int val=s.top();
    s.pop();
    insert(s, temp);
    // put the temp after sorting 
    s.push(val);
    // return;
}

void sortStack(stack<int> &s)
{
    if(s.size()==1)
    return;
    int temp=s.top();
    s.pop();
    // keep doing the pop operation till 1 ele is left, and then call insert function for that ele
    sortStack(s);
    insert(s, temp);
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
    sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
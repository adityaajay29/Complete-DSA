#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int>&q)
{
    if(q.empty())
    return;
    int temp=q.front();
    q.pop();
    reverseQueue(q);
    // last popped to be pushed first
    q.push(temp);
}

int main()
{
    queue<int>q;
    q.push(18);
    q.push(16);
    q.push(2);
    q.push(10);
    q.push(5);
    reverseQueue(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
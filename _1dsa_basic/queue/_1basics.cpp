#include <iostream>
#include <queue>
using namespace std;

// queue is also a container adapter
// can be implemented using list or dequeue
// vector cant be used as it doenst provide pop_front in O(1) time

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
    while(q.empty()!=true)
    {
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop();
    }
    return 0;
}

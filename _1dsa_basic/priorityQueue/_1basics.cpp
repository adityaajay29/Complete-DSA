// p. queue in c++ stl is always implemented using heap data structure
// in c++, by default it is max heap priority queue
// queue library used to create the pr queue
// priority queues are based on cocept of heap, but is built on the top of dynamic arrays
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    while(pq.empty()!=true)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    if(pq.empty()==true)
    cout<<"true"<<endl;
    return 0;
}

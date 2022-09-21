#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // creating a priority queuw, which keeps min element on the top, as root
    priority_queue< int,vector<int>,greater<int> >pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    while(pq.empty()!=true)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
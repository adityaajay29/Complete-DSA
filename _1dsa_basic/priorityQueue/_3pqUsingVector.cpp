#include <iostream>
#include <queue>
#include<vector>
using namespace std;
int main()
{
    vector<int>v{10,5,15,2,34,23,33,1};

    // buildHeap is a O(n) function, as we have seen, 
    // while push and pop are O(logn)
    // creating a pq using buildHeap, using vector is more efficient in time complexity

    // creating a minHeap using vector, and BuildHeap
    priority_queue< int,vector<int>,greater<int> >pq(v.begin(),v.end());
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl<<endl;
    while(pq.empty()!=true)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
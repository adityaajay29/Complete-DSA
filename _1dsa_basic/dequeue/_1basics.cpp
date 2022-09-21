#include <iostream>
#include <deque>
using namespace std;

// push_back O(1)
// push_front O(1)
// pop_front, pop_back O(1)
// random access O(1)
// earse and insert at any position is O(n)

int main()
{
    deque<int>deq{10,20,30};
    deq.push_front(5);
    deq.push_back(50);
    for(auto x:deq)
    {
    cout<<x<<" ";
    }
    cout<<endl;
    cout<<deq.front()<<" "<<deq.back()<<endl;

    auto itr=deq.begin();
    itr++; //itr poits now 2nd element
    deq.insert(itr,35); //inserts 35 before the 2nd element
    deq.pop_front();
    deq.pop_back();
    cout<<deq.size()<<endl;
    auto it=deq.begin();
    deq.insert(it,3,4); //iterater at 35
    // deq.erase(it);
    cout<<*it<<endl;
    return 0;
}
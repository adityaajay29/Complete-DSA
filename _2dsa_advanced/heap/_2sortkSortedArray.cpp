#include <iostream>
#include <queue>
using namespace std;

// store only the k elements in the pq
// sorting will take O(nlogn), but this will take O(nlogk)
// space :O(n)

void kSortedArray(vector<int>&v,int k)
{
    int n=v.size();
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<=k;i++)
    {
        pq.push(v[i]);
    }
    // maintaining an index variable to put ele back to v in sorted way
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        v[index++]=pq.top();
        pq.pop();
        pq.push(v[i]);
    }
    // put back the left elements in the v
    while(!pq.empty())
    {
        v[index++]=pq.top();
        pq.pop();
    }   
}

int main()
{
    vector<int>v{9,8,7,18,19,17};
    int k=2;
    kSortedArray(v,k);
    for(auto x:v)
    cout<<x<<" ";
    return 0;
}
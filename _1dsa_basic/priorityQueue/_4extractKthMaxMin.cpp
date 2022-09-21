#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// O(n) time to build heap, instead of O(nlogn), and pop is constant operation in queue
// so overall O(n) time
void extractMinMax(vector<int>&v,int i)
{
    priority_queue<int>maxHeap(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int> >minHeap(v.begin(),v.end());
    int curr=0;
    while(curr<i-1)
    {
        minHeap.pop();
        curr++;
    }
    cout<<"the given minimum number is "<<minHeap.top()<<endl;
    cout<<"the maximum number is "<<maxHeap.top()<<endl;
}

int main()
{
    vector<int>v{34,27,199,-876,12,547,22,21};
    extractMinMax(v,3);
    return 0;
}
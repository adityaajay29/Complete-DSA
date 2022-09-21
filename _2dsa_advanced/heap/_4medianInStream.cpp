#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// approach : 
// we keep 2 heaps, one minHeap, another maxHeap
// maxheap to store greater eles
// minHeap to store smaller eles
// then do given steps
// time : O(nlogn)

vector<float> medianOfStream(vector<int>&arr)
{
    int n=arr.size();
    // creating a max heap to store smaller eles
    priority_queue<float>maxHeap;
    // creating a min heap to store larger eles
    priority_queue<int,vector<int>,greater<int> >minHeap;
    vector<float>ans;
    // processs the 1st ele separatly
    maxHeap.push(arr[0]);
    ans.push_back(maxHeap.top());
    for(int i=1;i<n;i++)
    {
        // case 1 : size of min and max heap is not same
        if(maxHeap.size()>minHeap.size())
        {
            // if curr ele is smaller than the top of maxHeap, put top(larger) in minHeap,
            // and then put curr(smaller) in maxHeap
            if(arr[i]<maxHeap.top())
            {
                int top=maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
                maxHeap.push(arr[i]);
            }
            // else, put curr in minHeap
            else 
            minHeap.push(arr[i]);
            // print the median as avg of max in 1st and min in 2nd, as sizes are same now
            ans.push_back((maxHeap.top()+minHeap.top())/2);
        }
        // case 2 : if sizes are same
        else 
        {
            // if curr ele is smaller than the top of maxHeap, put that in maxHeap
            if(arr[i]<=maxHeap.top())
            maxHeap.push(arr[i]);
            // else, put the curr(larger ele) in minheap
            // then put the top of MinHeap(smaller) in maxHeap
            else
            {
                minHeap.push(arr[i]);
                int top=minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
            // print the median as the top ele of maxheap
            ans.push_back(maxHeap.top());
        }
    }
    return ans;
}

int main()
{
    vector<int>arr{12,15,10,5,8,7,16};
    vector<float>ans=medianOfStream(arr);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int maxPurchase(vector<int>&v,int sum)
{
    int n=v.size();
    int count=0;
    if(n==0)
    return 0;
    // creating a minHeap
    priority_queue<int,vector<int>,greater<int> >pq(v.begin(),v.end());
    
    // if we see that cost is less than available sum
    while(!pq.empty() && sum-pq.top()>=0)
    {
        // increase count
        count++;
        // deduce that much amount
        sum-=pq.top();
        // goto next ele
        pq.pop();
    }
    return count;
}

int main()
{
    vector<int>v{20,10,5,30,100};
    int sum=64;
    cout<<"the max purchase with sum "<<sum<<" is "<<maxPurchase(v,sum)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// approach is to keep track of sum upto last ele
// make curr sum as max of (sum till last+v[i] and v[i] )
// return max sum
// Kadane's Algo 

int maxSubarraySum(vector<int>v,int n)
{
    int sum=v[0];
    int curr=v[0];
    for(int i=1;i<n;i++)
    {
        curr=max((curr+v[i]),v[i]);
        sum=max(sum,curr);
    }
    return sum;
}

int main()
{
    vector<int>v{-5,1,-2,3,-1,2,-2};
    int n=v.size();
    cout<<"the max subarray sum is "<<maxSubarraySum(v,n)<<endl;
    return 0;
}
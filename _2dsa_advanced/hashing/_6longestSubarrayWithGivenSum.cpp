#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>arr,int sum)
{
    // map to store ele and its index, to find the length of subarray
    unordered_map<int,int>mp;
    int prefixSum=0;
    int n=arr.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=arr[i];
        // corner case if a prefix sum is also the given sum
        if(prefixSum==sum)
        res=i+1;
        // only storing the leftmost prefix sum if repeated
        if(mp.find(prefixSum)==mp.end())
        {
            mp[prefixSum]=i;
        }
        if(mp.find(prefixSum-sum)!=mp.end())
        {
            res=max(res,i-mp[prefixSum-sum]);
        }
    }
    return res;
}

int main()
{
    vector<int>arr{2,8,10,-4,-6,10,15};
    int sum=10;
    cout<<"the length of longest subarray is "<<longestSubarray(arr,sum)<<endl;
    return 0;
}
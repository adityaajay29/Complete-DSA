#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// problem : Given two binary arrays of same length find the longest 
// subarray in the two arrays with equal sum and starting and ending at the same index in both arrays

int longestSubarraysinBoth(vector<int>arr1,vector<int>arr2)
{
    int n=arr1.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        arr1[i]=arr1[i]-arr2[i];
        // we can also do arr1=arr2-arr1
    }
    int prefixSum=0;
    int sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=arr1[i];
        if(prefixSum==sum)
        res=i+1;
        if(mp.find(prefixSum)==mp.end())
        mp[prefixSum]=i;
        if(mp.find(prefixSum-sum)!=mp.end())
        {
            res=max(res,i-mp[prefixSum-sum]);
        }
    }
    return res;
}

int main()
{
    vector<int>arr1{0,1,0,0,0,0};
    vector<int>arr2{1,0,1,0,0,1};
    cout<<"the longest subarrays in both the arrays with same starting and ending index and equal sum is ";
    cout<<longestSubarraysinBoth(arr1,arr2)<<endl;
    return 0;
}
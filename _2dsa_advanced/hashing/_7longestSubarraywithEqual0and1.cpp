#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// *******************************VERY FAMOUS INTERVIEW PROBLEM***************************
// similar problem to longest subarray with given sum

int longestSubarray(vector<int>&arr)
{
    int n=arr.size();
    // replacing 0s with -1
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        arr[i]=-1;
    }
    // mp for storing prefix Sum and it 1st occurance index
    unordered_map<int,int>mp;
    int prefixSum=0;
    int sum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        prefixSum+=arr[i];
        // corner case  
        if(prefixSum==sum)
        res=i+1;
        // storing index of 1st occurance of each prefixSum
        if(mp.find(prefixSum)==mp.end())
        mp[prefixSum]=i;
        // if we find ele in mp with sum-prefixSum, find the distance between that index and the ele index
        if(mp.find(prefixSum-sum)!=mp.end())
        {
            res=max(res,i-mp[prefixSum-sum]);
        }
    }
    return res;
}

int main()
{
    vector<int>arr{1,0,1,1,1,0,0};
    cout<<"the longest subarray with equal 0s and 1s is "<<longestSubarray(arr)<<endl;
    return 0;
}
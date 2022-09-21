#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(int x : arr)
        totalSum += x;
    
    vector<bool>prev(totalSum + 1);
    
    prev[0] = true;
    
    if(arr[0] <= totalSum)
        prev[arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        vector<bool> curr(totalSum+1);
        curr[0] = true;
        for(int j=1;j<=totalSum;j++)
        {
            bool take = false;
            if(arr[i] <= j)
                take = prev[j-arr[i]];
            bool notTake = prev[j];
            curr[j] = take || notTake;
        }
        prev= curr;
    }
    int minDiff = 1e9;
    for(int i=0;i<=totalSum/2;i++)
    {
        if(prev[i] == true)
        {
            int s1 = i;
            int s2 = totalSum - i;
            minDiff = min(minDiff, abs(s1-s2));
        }
    }
    return minDiff;
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<minSubsetSumDifference(arr, n)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(int x : arr)
        totalSum += x;
    
    vector<vector<bool> > dp(n, vector<bool> (totalSum + 1));
    for(int i=0;i<n;i++)
    {
        dp[i][0] = true;
    }
    if(arr[0] <= totalSum)
        dp[0][arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=totalSum;j++)
        {
            bool take = false;
            if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
            bool notTake = dp[i-1][j];
            dp[i][j] = take || notTake;
        }
    }
    int minDiff = 1e9;
    // optimisiing linear serach by checking only left half, 
    // as right half will also give same abs diff
    for(int i=0;i<=totalSum/2;i++)
    {
        // here, i signifies the range of totalSum
        if(dp[n-1][i] == true)
        {
            // if for given i, the dp iss filled with true, means that i is possible candidtae for s1
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
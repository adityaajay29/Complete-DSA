#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &arr, vector<int> &dp)
{
    int n=arr.size();

    // if i<0, then it will not be having any ele, then the sum will be 0
    // if no ele, sum = 0;
    int neg = 0;

    // if i == 1, then sum == arr[0];
    // if 1 ele, sum  = arr[0]
    dp[0] = arr[0];

    for(int i=1;i<n;i++)
    {
        int take = arr[i];
        if(i>1)
        take += dp[i-2];
        int notTake = 0 + dp[i-1];
        dp[i] = max(take, notTake);
    }
    return dp[n-1];
}

int main()
{
    vector<int> arr{5, 6, 6};
    int n = arr.size();
    vector<int> dp(n);
    cout<<maxSum(arr, dp);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &arr, int i, vector<int> &dp)
{
    if(i == 0)
    return arr[i];
    if(i < 0)
    return 0;

    if(dp[i] != -1)
    return dp[i];

    int take = arr[i] + maxSum(arr, i-2, dp);
    int notTake = 0 + maxSum(arr, i-1, dp);

    return dp[i] = max(take, notTake);
}

int main()
{
    vector<int> arr{5,6,6};
    int n = arr.size();
    vector<int> dp(n+1, -1);
    cout<<maxSum(arr, n-1, dp);
    return 0;
}

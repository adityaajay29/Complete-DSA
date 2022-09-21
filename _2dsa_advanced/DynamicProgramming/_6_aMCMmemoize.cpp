#include <iostream>
#include <vector>
using namespace std;

// changing vars are i and j, so dp[i+1][j+1]

int dp[101][101];

int mcm(vector<int>&arr, int i, int j)
{
    if(i >= j)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        // multiplication for left and right sub arrays + current multiplication
        dp[i][j] = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, dp[i][j]);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    int n, val;
    cin>>n;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    memset(dp, -1, sizeof(dp));
    cout<<"the min cost of mcm is "<<mcm(arr, 1, n-1)<<endl;
    return 0;
}
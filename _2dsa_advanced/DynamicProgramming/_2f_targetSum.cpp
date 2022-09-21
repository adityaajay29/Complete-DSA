#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp[1001][1001];

int subsetSum(vector<int> &arr, int n, int sum, int count0)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i == 0)
            dp[i][j]=0;
            if(j == 0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j && arr[i-1] != 0)
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum]*pow(2, count0);
}

// int memoise(vector<int> &arr, int n,  int sum, int count0)
// {
//     if(n == 0)
//     {
//         if(sum == 0)
//             return 1;
//         return 0;
//     }
//     if(dp[n][sum] != -1)
//     return dp[n][sum];
//     int ans=0;
//     if(arr[n-1] <= sum && arr[n-1] != 0)
//     ans = memoise(arr, n-1, sum-arr[n-1], count0) + memoise(arr, n-1, sum, count0);
//     else 
//     ans = memoise(arr, n-1, sum, count0);
//     return dp[n][sum] = ans*pow(2, count0);
// }

int targetSum(vector<int> &arr, int target)
{
    int s=0;
    int count0=0;
    int n=arr.size();
    // memset(dp, -1, sizeof(dp));
    for(auto x: arr)
    {
        if(x == 0)
        count0++;
        s+=x;
    }
    if((s+target) %2 || s<target)
    return 0;
    int sum=(s+target)/2;
    return subsetSum(arr, n, sum, count0);
}

int main()
{
    int n, target, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>target;
    cout<<"the number of combinations with target sum are "<<targetSum(arr, target)<<endl;
    return 0;
}
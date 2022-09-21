#include <iostream>
#include <vector>
using namespace std;

// problem : 
// Coin Change Problem Maximum Number of ways : 
// Given a value N, if we want to make change for N cents, 
// and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
// how many ways can we make the change? The order of coins doesn’t matter.

// eg : 
// n=5, coins : (1, 2, 3)
// o/p = 5
// 1,1,1,1,1 ; 1,1,1,2 ; 1,1,3 ; 1,2,2; 2,3;

// similar to subset sum problem, except for, it is unbounded (infinite supply of each coin)

int dp[102][102];

int countWays(vector<int> &coins, int n, int sum)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i == 0)
            dp[i][j] = 0;
            if(j == 0)
            dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1] <= j)
            dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    vector<int> coins;
    int val;
    cin>>n;
    int i=n;
    while(i--)
    {
        cin>>val;
        coins.push_back(val);
    }
    cin>>sum;
    cout<<"the no of combinations with sum "<<sum<<" are "<<countWays(coins, n, sum)<<endl;
    return 0;
}
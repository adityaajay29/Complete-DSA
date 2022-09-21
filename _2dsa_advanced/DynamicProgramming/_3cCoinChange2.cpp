#include <iostream>
#include <vector>
using namespace std;

// ************ spacial problem ************

int dp[102][102];

int minCoins(vector<int> &coins, int n, int amount)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(i == 0)
            // infinite coins needed to get required amount if we dont have any coin of any val
            dp[i][j] = INT_MAX-1;
            if( j == 0 && i!=0)
            // 0 coins needed to get 0 amount
            dp[i][j] = 0;
        }
    }
    // initialising 2nd row
    for(int j=1;j<=amount;j++)
    {
        // if amount j is divisible by coin val, then only we can make that amount
        if(j % coins[0] == 0)
        dp[1][j] = j/coins[0];
        else
        // else, infinite coins needed to make that amount with the given coin val
        dp[1][j] = INT_MAX-1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(coins[i-1] <= j)
            dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
    // if combination not possible, return -1
    // if(dp[n][amount] == INT_MAX-1)
    // return -1;
    return (dp[n][amount] == INT_MAX-1 ? -1 :  dp[n][amount]);
}

int main()
{
    int n, amount, val;
    vector<int> coins;
    cin>>n;
    int i=n;
    while(i--)
    {
        cin>>val;
        coins.push_back(val);
    }
    cin>>amount;
    cout<<"min no of coins to get amount of "<<amount<<" is "<<minCoins(coins, n, amount)<<endl;
    return 0;
}
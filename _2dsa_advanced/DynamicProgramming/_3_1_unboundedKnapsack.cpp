#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];

// memoisation (top down)

int knapsack(vector<int> &val, vector<int> &wt, int w, int n)
{
    // base case
    if(n == 0 || w == 0)
    return 0;

    if(dp[n][w] != -1)
    return dp[n][w];

    if(wt[n-1] <= w)
    return dp[n][w] = max(val[n-1] + knapsack(val, wt, w-wt[n-1], n), knapsack(val, wt, w, n-1));
    else
    return dp[n][w] = knapsack(val, wt, w, n-1);
}

// bottom up

int tabulation(vector<int> &val, vector<int> &wt, int w, int n)
{
    // initialisation
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1] <= j)
            dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main()
{
    int n, w, val1, val2;
    cin>>n;
    vector<int> val, wt;
    int i=n;
    while(i--)
    {
        cin>>val1>>val2;
        wt.push_back(val1);
        val.push_back(val2);
    }
    cin>>w;
    // memset(dp, -1, sizeof(dp));
    // cout<<"the max profit is "<<knapsack(val, wt, w, n)<<endl;
    cout<<"the max profit is "<<tabulation(val, wt, w, n)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// problem 
// Given a rod of length n inches and an array of prices 
// that contains prices of all pieces of size smaller than n. 
// Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 

int dp[102][102];

int maxProfit(vector<int> &l, vector<int> &val, int N, int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(l[i-1] <= j)
            dp[i][j] = max(val[i-1] + dp[i][j-l[i-1]], dp[i-1][j]);
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][N];
}

int main()
{
    int N, val1;
    vector<int> l, val;
    cin>>N;
    int i=N;
    while(i--)
    {
        cin>>val1;
        val.push_back(val1);
    }
    for(int i=0;i<N;i++)
    {
        l.push_back(i+1);
    }
    int n=N;
    cout<<"the max profit after cutting rods is "<<maxProfit(l, val, N, n)<<endl;
}
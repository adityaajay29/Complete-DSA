#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int> > &t, int n, vector<vector<int> >&dp)
{
    for(int j=0;j<n;j++)
    {
        dp[n-1][j] = t[n-1][j];
    }

    for(int i = n-2;i>=0;i--)
    {
        int m = t[i].size();
        for(int j=m-1;j>=0;j--)
        {
            int up = dp[i+1][j];
            int diag = dp[i+1][j+1];
            dp[i][j] = t[i][j] + min(up, diag);
        }
    }
    return dp[0][0];
}

int main()
{
    int n;
    cin>>n;
    int u;
    vector<vector<int> >t(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>u;
            t[i][j] = u;
        }
    }
    vector<vector<int> >dp(n, vector<int> (n));
    cout<<"min path sum is "<<solve(t, n, dp)<<endl;
    return 0;
}
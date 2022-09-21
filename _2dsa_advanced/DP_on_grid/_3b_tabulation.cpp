#include <iostream>
#include <vector>
using namespace std;

int solve(int m, int n, vector<vector<int> > &grid, vector<vector<int> > &dp)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
            dp[i][j] = grid[i][j];
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;

                if(i > 0)
                up = dp[i-1][j];

                if(j > 0)
                left = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m, n;
    cin>>m>>n;
    int u;
    vector<vector<int> >grid(m, vector<int> (n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>u;
            grid[i][j] = u;
        }
    }
    vector<vector<int> >dp(m, vector<int> (n));
    cout<<solve(m, n, grid, dp)<<endl;
    return 0;
}
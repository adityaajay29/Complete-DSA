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
            dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if(i > 0 && grid[i-1][j] != -1)
                up = dp[i-1][j];

                if(j > 0 && grid[i][j-1] != -1)
                left = dp[i][j-1];

                dp[i][j] = up + left;
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
    if(grid[0][0] == -1 || grid[m-1][n-1] == -1)
    cout<<"the unique paths from 0, 0 to m-1, n-1 are "<<0<<endl;
    else
    cout<<"the unique paths from 0, 0 to m-1, n-1 are "<<solve(m, n, grid, dp)<<endl;
    return 0;
}
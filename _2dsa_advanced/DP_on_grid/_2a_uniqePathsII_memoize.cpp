#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp)
{
    if(i == 0 && j == 0)
    return 1;

    if(i < 0 || j < 0)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int up = 0;
    int left = 0;

    if(i > 0 && grid[i-1][j] != 1)
    up = solve(i-1, j, grid, dp);

    if(j > 0 && grid[i][j-1] != 1)
    left = solve(i, j-1, grid, dp);

    return dp[i][j] =  up + left;
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
    vector<vector<int> >dp(m, vector<int> (n, -1));
    cout<<"the unique paths from 0, 0 to m-1, n-1 avoiding obstacles are "<<solve(m-1, n-1, grid, dp)<<endl;
    return 0;
}

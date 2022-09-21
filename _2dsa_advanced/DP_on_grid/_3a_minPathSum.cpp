#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp)
{
    if(i == 0 && j == 0)
    return grid[0][0];

    if(i < 0 || j < 0)
    return INT_MAX;

    if(dp[i][j] != -1)
    return dp[i][j];

    int up = solve(i-1, j, grid, dp);
    int left = solve(i, j-1, grid, dp);
    return dp[i][j] = grid[i][j] + min(up, left);
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
    cout<<"min path sum is "<<solve(m-1, n-1, grid, dp)<<endl;
    return 0;
}
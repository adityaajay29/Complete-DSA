#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int> > &matrix, vector<vector<int> > &dp)
{
    if(j < 0 || j >= matrix[0].size())
        return -1e9;
    
    if(i == 0)
        return matrix[0][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = solve(i-1, j, matrix, dp);
    int dl = solve(i-1, j-1, matrix, dp);
    int dr = solve(i-1, j+1, matrix, dp);
    return dp[i][j] = matrix[i][j] + max(up, max(dl, dr));
}

int getMaxPathSum(vector<vector<int> > &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = -1e9;
    vector<vector<int> > dp(n, vector<int> (m, -1));
    for(int j=0;j<m;j++)
    {
        int ans = solve(n-1, j, matrix, dp);
        maxSum = max(maxSum, ans);
    }
    return maxSum;
}
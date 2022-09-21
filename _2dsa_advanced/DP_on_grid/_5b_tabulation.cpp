#include <iostream>
#include <vector>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = -1e9;
    vector<vector<int>> dp(n, vector<int> (m));
    for(int j=0;j<m;j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
                {
                    int up = -1e9;
                    int dl = -1e9;
                    int dr = -1e9;
                    up = dp[i-1][j];
                    if(j-1 >= 0)
                        dl = dp[i-1][j-1];
                    if(j + 1 < m)
                        dr = dp[i-1][j+1];
                    dp[i][j] = matrix[i][j] + max(up, max(dl, dr));
                }  
    }
    for(int j=0;j<m;j++)
    {
        maxSum = max(maxSum, dp[n-1][j]);
    }
    return maxSum;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int> > dp(N, vector<int> (N));
        for(int i=1;i<N;i++)
        {
            dp[i][i] = 0;
        }
        
        for(int i=N-1;i>=1;i--)
        {
            for(int j=i+1;j<N;j++)
            {
                int mini = INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int step = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, step);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][N - 1];
    }
};
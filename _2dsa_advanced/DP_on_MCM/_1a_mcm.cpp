#include <iostream>
#include <vector>
using namespace std;

// steps : 
// 1. start with entire array
// 2. try all partitions (run a loop for that)
// 3. return the best possible 2 partitions

class Solution{
public:
    int solve(int i, int j, int arr[], vector<vector<int> > &dp)
    {
        if(i == j)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int part = INT_MAX;
        
        // try all partitions
        // we can partition upto j - 1 as matrix will have 2d
        for(int k=i;k<j;k++)
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
            // return part to minimise the multiplication
            part = min(part, steps);
        }
        return dp[i][j] = part;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int> > dp(N, vector<int> (N, -1));
        // start with complete array, since matrix will have 2d, so i starts from 1
        return solve(1, N - 1, arr, dp);
    }
};
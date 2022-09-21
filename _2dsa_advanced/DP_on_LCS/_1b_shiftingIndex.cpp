#include <iostream>
#include <vector>
using namespace std;

int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        // since tabulation with -ve index was not possible, so we shifted the indices by 1
        // so, dp[m][n] changes to dp[m+1][n+1]
        // and base case changes to (i == 0 || j == 0)
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + solve(s1, s2, i-1, j-1, dp);
        else 
            return dp[i][j] = 0 + max(solve(s1, s2, i-1, j, dp), solve(s1, s2, i, j-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        
        return solve(text1, text2, m, n, dp);
    }
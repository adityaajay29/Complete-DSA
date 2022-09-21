#include <iostream>
#include <vector>
using namespace std;

    int solve(string &s1, string &s2, int i, int j, vector<vector<int> > &dp)
    {
        if(i == 0 || j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
        
        return dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
    }
    
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
        
        int lcs = solve(s, s1, n, n, dp);
        
        return n - lcs;
    }
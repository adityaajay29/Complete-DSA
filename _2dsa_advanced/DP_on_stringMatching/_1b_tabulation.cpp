#include <iostream>
#include <vector>
using namespace std;

// question link : https://leetcode.com/problems/distinct-subsequences/

int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double> > dp(m + 1, vector<double> (n + 1, 0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0] = 1;
        }
        
//         we start from j = 1, as, dp[0][0] should be 1, i.e., when both strings have exhausted
//         meaning there was a match 
        for(int j=1;j<=n;j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[m][n];
    }
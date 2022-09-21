#include <iostream>
#include <vector>
using namespace std;

// question link : https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int> > &dp)
    {
//         if we matched all chars of t in s, then only we reached here
        if(j < 0)
            return 1;
        
//         if s exhausted and t still has some char to match, means match isnt there anymore
        if(i < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
//             if matching, there can be two cases : 
//             either take the curr matching and move to next char in s and t both 
//             or search for any other match in s for the same matching char
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
        
//         if not matching, then definitly look if there is other match of curr char of t in s
        return dp[i][j] = solve(s, t, i - 1, j, dp);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int> > dp(m , vector<int> (n, -1));
        
        return solve(s, t, m - 1, n - 1, dp);
    }
};
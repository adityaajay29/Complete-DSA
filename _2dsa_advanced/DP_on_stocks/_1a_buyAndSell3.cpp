#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &prices, int i, bool buy, int cap, vector<vector<vector<int> > > &dp)
    {
        if(cap == 0)
            return 0;
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        if(buy)
        {
            return dp[i][buy][cap] = max(-prices[i] + solve(prices, i + 1, false, cap, dp), 
                                         0 + solve(prices, i + 1, true, cap, dp));
        }
        // else
            return dp[i][buy][cap] =  max(prices[i] + solve(prices, i + 1, true, cap - 1, dp), 
                                          0 + solve(prices, i + 1, false, cap, dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        int cap = 2;
        vector<vector<vector<int> > > dp(n, vector<vector<int> > (2, vector<int> (cap + 1, -1)));
        return solve(prices, 0, buy, cap, dp);
    }
};
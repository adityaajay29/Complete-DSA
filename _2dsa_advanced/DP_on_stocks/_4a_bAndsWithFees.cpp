#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &prices, int &fee, int i, bool buy, vector<vector<int>> &dp)
    {
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        if(buy)
        {
            return dp[i][buy] = max(-prices[i] + solve(prices, fee, i + 1, false, dp),
                                    0 + solve(prices, fee, i + 1, true, dp));
        }
//         else
        return dp[i][buy] = max(prices[i] - fee + solve(prices, fee, i + 1, true, dp),
                                0 + solve(prices, fee, i + 1, false, dp));
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return solve(prices, fee, 0, true, dp);
    }
};
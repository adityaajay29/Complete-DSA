#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        
        for(int i=n-1;i>=0;i--)
        {
//             buy = true
            dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
//             buy = false
            dp[i][0] = max(prices[i] - fee + dp[i + 1][1], 0 + dp[i + 1][0]);
        }
        return dp[0][1];
    }
};
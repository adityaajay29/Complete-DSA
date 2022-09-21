#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int> (k + 1, 0));
        vector<vector<int>> curr(2, vector<int> (k + 1, 0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap = 1;cap <= k;cap++)
                {
                    if(buy == 1)
                    {
                        curr[buy][cap] = max(-prices[i] + next[0][cap], 0 + next[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(prices[i] + next[1][cap - 1], 0 + next[0][cap]);
                    }
                }
            }
            next = curr;
        }
        return next[1][k];
    }
};
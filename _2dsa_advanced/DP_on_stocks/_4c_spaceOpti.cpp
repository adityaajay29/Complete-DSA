#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);
        
        for(int i=n-1;i>=0;i--)
        {
//             buy = true
            curr[1] = max(-prices[i] + next[0], 0 + next[1]);
//             buy = false
            curr[0] = max(prices[i] - fee + next[1], 0 + next[0]);
            
            next = curr;
        }
        return next[1];
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int i, int prevInd, vector<vector<int> > &dp)
    {
        if(i == nums.size())
            return 0;
        
//         storing at -1 as index is not possible, so shifting prev by 1
        if(dp[i][prevInd + 1] != -1)
            return dp[i][prevInd + 1];
        
        int notTake = 0 + solve(nums, i + 1, prevInd, dp);
        int take = 0;
        if(prevInd == -1 || nums[i] > nums[prevInd])
            take = 1 + solve(nums, i + 1, i, dp);
        
        return dp[i][prevInd + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};
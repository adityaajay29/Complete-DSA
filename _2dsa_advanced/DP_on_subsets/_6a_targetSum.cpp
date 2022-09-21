#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int i, int sum, vector<vector<int> > &dp)
    {
        if(i == 0)
        {
            // base case 1 : if there is one ele, and that is 0, and sum is also 0
            //               then we can either take it, or not take it, both will not alter the sum
            //               hence, 2 ways
            if(nums[i] == 0 && sum == 0)
                return 2;

            // base case 2 : if there is only one ele and its value is equal to sum, then take 1
            //               even if the sum is 0 and ele is not 0, then we have a choice of not taking
            //               hence, 1 way
            if(nums[i] == sum || sum == 0)
                return 1;
            
            // in all other cases, 0 ways
            return 0;
        }
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        int take = 0;
        int notTake = solve(nums, i - 1, sum, dp);
        if(nums[i] <= sum)
        {
            take = solve(nums, i - 1, sum - nums[i], dp);
        }
        return dp[i][sum] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int x : nums)
            totalSum += x;
        
        if(totalSum - target < 0 || (totalSum - target) % 2)
            return 0;
        
        int sum = (totalSum - target)/2;
        
        vector<vector<int> > dp(n, vector<int> (sum + 1, -1));
        
        return solve(nums, n-1, sum, dp);
    }
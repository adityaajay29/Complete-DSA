#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int x : nums)
            totalSum += x;
        
        if(totalSum - target < 0 || (totalSum - target) % 2)
            return 0;
        
        int sum = (totalSum - target)/2;
        
        vector<vector<int> > dp(n, vector<int> (sum + 1));
        
        // base case 1 : if sum is 0 and num[0] is also 0, then we have 2 choices
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
        // base case 2 : if sum is 0 but num[0] is not 0, then we have 1 choice of not taking it
            dp[0][0] = 1;
        
        // base case 2 : if num[0] == sum and num[0] != 0 (as this will alter result of dp[0][0] = 2),  
        // then we can take it, one way
        if(nums[0] <= sum && nums[0] != 0)
            dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int take = 0;
                int notTake = dp[i-1][j];
                if(nums[i] <= j)
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][sum];
    }
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
        
        vector<int> prev(sum + 1);
        
        if(nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        
        if(nums[0] <= sum && nums[0] != 0)
            prev[nums[0]] = 1;
        
        for(int i=1;i<n;i++)
        {
            vector<int> curr(sum + 1);
            for(int j=0;j<=sum;j++)
            {
                int take = 0;
                int notTake = prev[j];
                if(nums[i] <= j)
                    take = prev[j-nums[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
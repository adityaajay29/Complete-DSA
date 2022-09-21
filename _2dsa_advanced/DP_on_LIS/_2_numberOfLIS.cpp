#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 1;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    // if we get better lis when adding 1 to dp[j], then count will be same as prev 
                    if(dp[i] < 1 + dp[j])
                    {
                        dp[i] = max(dp[i], 1 + dp[j]);
                        count[i] = count[j];
                    }
                    // we lis becomes same on add in 1 to dp[j], then accumulate count of j to i
                    else if(dp[i] == 1 + dp[j])
                    {
                        count[i] += count[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i] == maxi)
            {
                ans += count[i];
            }
        }
        return ans;
    }
};
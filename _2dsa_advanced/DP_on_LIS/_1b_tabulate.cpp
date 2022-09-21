#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prevInd=i-1;prevInd>=-1;prevInd--)
            {
                int take = 0;
                // shifting prevIndex by 1 so that negative index is not accessed
                int notTake = dp[i + 1][prevInd + 1];
                if(prevInd == -1 || nums[i] > nums[prevInd])
                    take = 1 + dp[i + 1][i + 1];
                dp[i][prevInd + 1] = max(take, notTake);
            }
        }
        return dp[0][-1 + 1];
    }
};
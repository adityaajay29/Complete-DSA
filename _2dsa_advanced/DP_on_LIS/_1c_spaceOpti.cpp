#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int take = 0;
                int notTake = next[j + 1];
                if(j == -1 || nums[i] > nums[j])
                    take = 1 + next[i + 1];
                curr[j + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[-1 + 1];
    }
};
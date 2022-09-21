#include <iostream>
#include <vector>
using namespace std;

    bool dp[202][20002];
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int wt=nums[0];
        for(int i=1;i<n;i++)
        {
            wt+=nums[i];
        }
        
        if(wt%2)
            return false;
        
        //problem boils down to subset sum problem of 01knapsack approach
        
        int sum=wt/2;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    int val;
    int i=n;
    while(i--)
    {
        cin>>val;
        nums.push_back(val);
    }
    cout<<canPartition(nums);
    return 0;
}
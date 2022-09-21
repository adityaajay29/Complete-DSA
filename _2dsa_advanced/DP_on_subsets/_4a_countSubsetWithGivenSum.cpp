#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int tar, int i, vector<vector<int> > &dp)
{
    // if(tar == 0)
    //     return 1;
    
    // if(i == 0)
    // {
    //     return(nums[i] == tar ? 1 : 0);
    // }


    // changes when tc is like : {0,0,0,1};

    if(i == 0)
    {
        // if the target is 0 and arr[0] is also 0,we have 2 options : 
        // either take 0 or not take 0, both will not alter the ans
        if(tar == 0 && nums[0] == 0)
        return 2;
        // if target is 0, subset is always possible with 0 sum 
        // if target is same as num[0], then also we can take it
        if(tar == 0 || nums[0] == tar)
        return 1;
        // in all other ways, it will give 0 
        return 0;
    }
    
    if(dp[i][tar] != -1)
        return dp[i][tar];
    
    int take = 0;
    if(nums[i] <= tar)
        take = solve(nums, tar - nums[i], i - 1, dp);
    int notTake = solve(nums, tar, i - 1, dp);
    return dp[i][tar] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (tar + 1, -1));
    return solve(num, tar, n - 1, dp);
}

int main()
{
    int n, sum, val;
    cin>>n;
    vector<int> num;
    int i=n;
    while(i--)
    {
        cin>>val;
        num.push_back(val);
    }
    cin>>sum;
    cout<<findWays(num, sum)<<endl;
    return 0;
}
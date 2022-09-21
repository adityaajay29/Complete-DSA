#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;
int solve(vector<int> &arr, int target, int i, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(target == 0 && arr[0] == 0)
            return 2;
        if(target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if(dp[i][target] != -1)
        return dp[i][target];
    int take = 0;
    if(arr[i] <= target)
        take = solve(arr, target - arr[i], i - 1, dp);
    int notTake = solve(arr, target, i - 1, dp);
    return dp[i][target] = (take + notTake) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int x : arr)
        sum += x;
    if(sum < d || (sum - d) % 2 == 1)
        return 0;
    
    int target = (sum - d)/2;
    vector<vector<int> > dp(n, vector<int> (target + 1, -1));
    return solve(arr, target, n - 1, dp);
}

int main()
{
    int n, d, val;
    cin>>n;
    vector<int> num;
    int i=n;
    while(i--)
    {
        cin>>val;
        num.push_back(val);
    }
    cin>>d;
    cout<<countPartitions(n, d, num)<<endl;
    return 0;
}
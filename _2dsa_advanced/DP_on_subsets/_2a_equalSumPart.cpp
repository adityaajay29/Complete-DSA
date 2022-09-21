#include <iostream>
#include <vector>
using namespace std;

bool solve(int i, int sum, vector<int> &arr, vector<vector<int> > &dp)
{
    if(sum == 0)
        return true;
    
    if(i == 0)
    {
        return(arr[0] == sum);
    }
    
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    bool take = false;
    if(arr[i] <= sum)
    {
        take = solve(i-1, sum - arr[i], arr, dp);
    }
    bool notTake = solve(i-1, sum, arr, dp);
    
    return dp[i][sum] = take || notTake;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int arrSum = arr[0];
    for(int i=1;i<n;i++)
    {
        arrSum += arr[i];
    }
    if(arrSum %2 == 1)
        return false;
    
    int sum = arrSum / 2;
    vector<vector<int> > dp(n, vector<int> (sum + 1, -1));
    return solve(n-1, sum, arr, dp);
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<canPartition(arr, n)<<endl;
    return 0;
}
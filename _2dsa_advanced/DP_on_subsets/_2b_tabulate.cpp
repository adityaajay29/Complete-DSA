#include <iostream>
#include <vector>
using namespace std;

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
    
    int sum = arrSum/2;
    vector<vector<bool>> dp(n, vector<bool> (sum + 1, false));
    
    for(int i=0;i<n;i++)
    {
        dp[i][0] = true;
    }
    
    dp[0][arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool take = false;
            if(arr[i] <= j)
                take = dp[i-1][j - arr[i]];
            bool notTake = dp[i-1][j];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][sum];
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
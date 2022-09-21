#include <iostream>
#include <vector>
using namespace std;

int subsetSum(int n, int sum, vector<int> &arr)
{
    vector<vector<bool> > dp(n, vector<bool> (sum+1, false));
    // base case 1
    for(int i=0;i<n;i++)
    {
        // 0th row and 0th col done
        dp[i][0] = true;

    }
    // base case 2
    dp[0][arr[0]] = true;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j)
            take = dp[i-1][j-arr[i]];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][sum];
}

int main()
{
    int n, sum, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>sum;
    cout<<subsetSum(n, sum, arr)<<endl;
    return 0;
}
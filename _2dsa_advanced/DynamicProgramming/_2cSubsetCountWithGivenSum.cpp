#include <iostream>
#include <vector>
using namespace std;

int dp[102][102];

int countSubset(vector<int> &arr, int sum, int n)
{
    // initialise
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i == 0)
            dp[i][j]=0;
            if(j == 0)
            dp[i][j]=1;
        }
    }
    // iteration
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            // fill dp with whatever we get considering both cases of including and excluding 
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
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
    cout<<"the subset count with sum "<<sum<<" is "<<countSubset(arr, sum, n);
    return 0;
}
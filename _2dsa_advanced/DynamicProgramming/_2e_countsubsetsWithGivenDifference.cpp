#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp[102][102];

int subsetSum(vector<int> &arr, int n, int sum)
{
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int diffCount(vector<int> &arr, int diff)
{
    int n=arr.size();
    int s=0;
    for(auto x:arr)
    s+=x;
    // if sum comes to be odd, then no combination possible
    if((s+diff)%2)
    return 0;
    int sum=(diff+s)/2;
    return subsetSum(arr, n, sum);
}

int main()
{
    int n, val, diff;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>diff;
    cout<<"the count of subsets with diff "<<diff<<" is "<<diffCount(arr, diff)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

bool dp[102][102];

// finding candidates for the subset {s1}
// problem boils fown to subset sum problem with subset as {s1} and sum as range

// the last row of the dp matrix will give whether the grid is valid candidate for {s1} or not
// if grid is true, then it is candidate for {s1}, put it in the array
// we only need half way of the last row, as half will automatically be handled as range-2{si};
// traverse this array and find the min difference as mini=min(mini, range-2arr[i]),
// where arr[i] is one of the candidate of {s1}

void subsetSum(vector<int> &arr, int n, int range)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=range;j++)
        {
            if(i == 0)
            dp[i][j]=0;
            if(j == 0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
}

int minDiff(vector<int> &arr)
{
    int n=arr.size();
    int range=0;
    for(int i=0;i<n;i++)
    {
        range+=arr[i];
    }
    subsetSum(arr, n, range);
    vector<int>ans;
    int sum=range/2;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n][i] == true)
        ans.push_back(i);
    }
    int mini=INT_MAX;
    for(int i=0;i<ans.size();i++)
    {
        mini=min(mini, range-2*ans[i]); 
    }
    return mini;
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
    cout<<"the min difference is "<<minDiff(arr)<<endl;
    return 0;
}
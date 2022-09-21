#include <iostream>
#include <vector>
using namespace std;

// problem : return if subset can be genearted from array elements having sum equal to given sum

// making dp matrix of true false
// if dp[n][sum] is true, it means we have found the subset with given sum

bool dp[102][102];

bool subSetSum(vector<int> &arr, int n, int sum)
{
    // initialisation
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i == 0)
            dp[i][j]=false;
            if(j == 0)
            dp[i][j]=true;
        }
    }
    // iteration
    // oring true false according to choices
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else 
            dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cin>>n;
    vector<int> arr;
    int i=n;
    int val;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>sum;
    cout<<subSetSum(arr, n, sum)<<endl;
    return 0;
}
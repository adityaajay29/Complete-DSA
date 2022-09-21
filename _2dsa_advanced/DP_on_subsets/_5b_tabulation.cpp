#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int x : arr)
        sum += x;
    if(sum < d || (sum - d) % 2 == 1)
        return 0;
    
    int target = (sum - d)/2;
    vector<vector<int> > dp(n, vector<int> (target + 1));
    if(arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if(arr[0] != 0 && arr[0]<= target)
        dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            int take = 0;
            if(arr[i] <= j)
                take = dp[i-1][j - arr[i]];
            int notTake = dp[i-1][j];
            dp[i][j] = (take + notTake) % mod;
        }
    }
    return dp[n-1][target];
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
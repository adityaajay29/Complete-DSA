#include <iostream>
#include <vector>
using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (tar + 1, 0));
    
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1;
    }
    
    if(num[0] <= tar)
        dp[0][num[0]] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int take = 0;
            if(num[i] <= j)
                take = dp[i - 1][j - num[i]];
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][tar];
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
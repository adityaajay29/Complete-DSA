#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &h, int n, vector<int> &dp, int k)
{
    if(n == 0)
    return 0;

    if(dp[n] != -1)
    return dp[n];

    int minEnergy = INT_MAX;
    int step = INT_MAX;
    for(int i = 1;i<=k;i++)
    {
        if(n-i >= 0)
        step = solve(h, n-i, dp, k) + abs(h[n] - h[n-i]);
        minEnergy = min(minEnergy, step);
    }
    return dp[n] = minEnergy;
}

int main()
{
    int n, val, k;
    cin>>n;
    vector<int> height;
    int i=n;
    while(i--)
    {
        cin>>val;
        height.push_back(val);
    }
    cin>>k;
    vector<int> dp(n+1, -1);
    cout<<"the min energy consumed with k jumps is "<<solve(height, n-1, dp, k)<<endl;
    return 0;
}

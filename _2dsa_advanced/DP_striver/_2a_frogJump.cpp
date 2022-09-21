#include <iostream>
#include <vector>
using namespace std;

// find min energy consumed by frog to reach from first stair to last stair
// frog can make either jump of 1, or 2 stairs
// enegry consumed = abs(height(ith stair) - height(i+1)th stair)

// many oveall sub problems
// memoize : 

int minEnergy(vector<int> &height, int n, vector<int> &dp)
{
    if(n == 0)
    return 0;

    if(dp[n] != -1)
    return dp[n];

    int two = INT_MAX;
    int one = minEnergy(height, n-1, dp) + abs(height[n] - height[n-1]);
    if(n>1)
        two = minEnergy(height, n-2, dp) + abs(height[n] - height[n-2]);

    return dp[n] = min(one, two);
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> height;
    int i=n;
    while(i--)
    {
        cin>>val;
        height.push_back(val);
    }
    vector<int> dp(n+1, -1);
    cout<<"the min energy consumed is "<<minEnergy(height, n-1, dp)<<endl;
    return 0;
}
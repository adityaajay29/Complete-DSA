#include <iostream>
#include <vector>
using namespace std;

int minEnergy(vector<int> &h, vector<int> &dp)
{
    int n = h.size();
    dp[0] = 0;
    int one;
    int two = INT_MAX;
    for(int i=1;i<n;i++)
    {
        one = dp[i-1] + abs(h[i] - h[i-1]);
        if(i>1)
        two = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(one, two);
    }
    return dp[n-1];
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
    vector<int> dp(n);
    cout<<"the min energy consumed is "<<minEnergy(height, dp)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int dp[101][101];

int lcss(string &s1, string &s2, int n, int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] = 0;
            }
        }
    }
    // the max substring can be anywhere, since we are also filling 0 in the dp when substring breaks
    int ans=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    int n, m;
    string s1, s2;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    cout<<"the longest common substring is "<<lcss(s1, s2, n, m)<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
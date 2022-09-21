#include <iostream>
using namespace std;

int dp[101][101];

int lrs(string s1)
{
    string s2=s1;
    int n=s1.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1] && i != j)
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string s1;
    cin>>s1;
    cout<<"the longest repeating subsquence is "<<lrs(s1)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int dp[101][101];

int palindrome(string &s)
{
    int n=s.size();
    string s1=s;
    reverse(s.begin(), s.end());
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1] == s1[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    // no of insertion to make p[alindrome will be same as no of deletion
    return n - dp[n][n];
}

int main()
{
    string s;
    cin>>s;
    cout<<"min insertion to make palindrome is "<<palindrome(s)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int dp[101][101];

int longestPalindrome(string &s1, string s2, int m, int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int makePalindrome(string &s)
{
    string revS=s;
    int n=s.size();
    reverse(s.begin(), s.end());
    int longest = longestPalindrome(s, revS, n, n);
    return n - longest;
}

int main()
{
    string s;
    cin>>s;
    cout<<"min no of deletion to make string palindrome is "<<makePalindrome(s)<<endl;
    return 0;
}
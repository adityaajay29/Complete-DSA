#include <iostream>
using namespace std;

int dp[101][101];

int convert(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();
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
            dp[i][j] = dp[i-1][j-1] + 1;
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int del = m - dp[m][n];
    int insert = n - dp[m][n];
    return del + insert;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<"the min no of deletion and insertion to convert "<<s1<<" to "<<s2<<" is "<<convert(s1, s2)<<endl;
    return 0;
}
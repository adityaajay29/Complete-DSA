#include <iostream>
using namespace std;

int dp[101][101];

void lcs(string &s1, string &s2, int m, int n)
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
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

string printLCS(string &s1, string &s2, int m, int n)
{
    lcs(s1, s2, m, n);
    int i=m, j=n;
    string ans="";
    while ( i || j)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else 
        {
            if(dp[i-1][j] > dp[i][j-1])
            i--;
            else
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int m, n;
    string s1, s2;
    cin>>s1>>s2;
    m=s1.size();
    n=s2.size();
    cout<<"the lcs is "<<printLCS(s1, s2, m, n)<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
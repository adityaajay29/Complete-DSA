#include <iostream>
using namespace std;

int dp[101][1001];

// can be done with bottom up also

int helper(string &s1, string &s2, int m, int n)
{
    if(n == 0 || m == 0)
    return 0;
    if(dp[m][n] != -1)
    return dp[m][n];
    if(s1[m-1] == s2[n-1])
    return dp[m][n] = 1 + helper(s1, s2, m-1,n-1);
    else
    return dp[m][n] = max(helper(s1, s2, m-1, n), helper(s1, s2, m, n-1));
}

int scss(string &s1, string &s2)
{
    int m=s1.size();
    int n=s2.size();
    memset(dp, -1,sizeof(dp));
    return m + n - helper(s1, s2, m, n);
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<"the length of shortest common superstring is "<<scss(s1, s2)<<endl;
    return 0;
}
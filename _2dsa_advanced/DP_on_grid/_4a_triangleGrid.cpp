#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int> > &t, vector<vector<int> > &dp)
{
    if(i == t.size() - 1)
    return t[i][j];

    if(dp[i][j] != -1)
    return dp[i][j];

    int down = solve(i+1, j, t, dp);
    int diag = solve(i+1, j+1, t, dp);
    return dp[i][j] = t[i][j] + min(down, diag);
}

int main()
{
    int n;
    cin>>n;
    int u;
    vector<vector<int> >t(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>u;
            t[i][j] = u;
        }
    }
    vector<vector<int> >dp(n, vector<int> (n, -1));
    cout<<"min path sum is "<<solve(0, 0, t, dp)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int solve(int m, int n, vector<vector<int> > &dp)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
            dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0)
                up = dp[i-1][j];
                if(j > 0)
                left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int> >dp(m, vector<int> (n));
    cout<<"the unique paths from 0, 0 to m-1, n-1 are "<<solve(m, n, dp)<<endl;
    return 0;
}
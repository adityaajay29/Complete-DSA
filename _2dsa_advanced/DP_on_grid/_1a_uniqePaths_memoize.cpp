#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int j, vector<vector<int> > &dp)
{
    if(i == 0 && j == 0)
    return 1;

    if(i < 0 || j < 0)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int left = solve(i, j-1, dp);
    int up = solve(i-1, j, dp);
    return left + up;
}

int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int> >dp(m, vector<int> (n, -1));
    cout<<"the unique paths from 0, 0 to m-1, n-1 are "<<solve(m-1, n-1, dp)<<endl;
    return 0;
}
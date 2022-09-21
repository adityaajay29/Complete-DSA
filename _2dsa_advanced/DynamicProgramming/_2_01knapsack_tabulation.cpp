#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[102][102];

int knapsackTD(vector<int> &wt, vector<int> &val, int w, int n)
{
    // initialisation of first row and column, instead of base case in the recursion
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j]=0;
        }
    }
    // iteration : 
    // change n with i, and w with j, i.e, 
    // n->i
    // w->j
    // change recurion to iteration in the if and else conditions
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1] <= j)
            {
                dp[i][j]=max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int n, w, val1, val2;
    cin>>n;
    vector<int> wt;
    vector<int> val;
    int i=n;
    while(i--)
    {
        cin>>val1>>val2;
        wt.push_back(val1);
        val.push_back(val2);
    }
    cin>>w;
    cout<<"the max profit is "<<knapsackTD(wt, val, w, n)<<endl;
    return 0;
}
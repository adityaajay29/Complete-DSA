#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[102][102];

int knapsack(vector<int> &wt, vector<int> &val, int w, int n)
{

    // base case
    // if no ele available or max wt is 0, then o profit
    if(n == 0 || w == 0)
    return 0;
    // either include or not, we have to remove the ele after making choice

    // if wt is small, then again choices to include or not

    // memoisation
    // we make matrix of variable that are changing in the recursion, here n and w

    // if value is already in dp, this is the ans, return it
    if(dp[n][w] != -1)
    return dp[n][w];

    if(wt[n-1] <= w)
    {
        // if included, we will add its val in the ans, else not 
        // ans will be max of those cases, and put ans in dp matrix
        return dp[n][w]= max((val[n-1] + knapsack(wt, val, w-wt[n-1], n-1)), knapsack(wt, val, w, n-1));
    }
    else if(wt[n-1] > w)
    {
        // not included, and put it in dp matrix
        return dp[n][w]= knapsack(wt, val, w, n-1);
    }
    return -1;
}

int maxProfit(vector<int> &wt, vector<int> &val, int w, int n)
{
    memset(dp, -1, sizeof(dp));
    return knapsack(wt, val, w, n);
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
    cout<<"the max profit is "<<maxProfit(wt, val, w, n)<<endl;
    return 0;
}

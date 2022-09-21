#include <iostream>
#include <vector>
using namespace std;

// tc : O(n), more optimised than memoization
// sc : O(n)

int fibonacci(int n, vector<int> &dp)
{
    // base case -> initialise
    dp[0] = 0;
    dp[1] = 1;

    // memoization -> tabulation
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1);
    cout<<fibonacci(n, dp)<<endl;
    return 0;
}
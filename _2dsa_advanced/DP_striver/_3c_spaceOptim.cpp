#include <iostream>
#include <vector>
using namespace std;

// since we are using only dp[i-1] and dp[1-2]
// then why not use only 2 variables, say prev1 and prev2 to store the vals
// just change the dp with curr, prev1 and prev2 

int solve(vector<int> &arr)
{
    int n = arr.size();
    int prev1 = arr[0];
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int take = arr[i];
        if(i>1)
        take += prev2;
        int notTake = prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> arr{5, 6, 6};
    int n = arr.size();
    cout<<solve(arr);
    return 0;
}
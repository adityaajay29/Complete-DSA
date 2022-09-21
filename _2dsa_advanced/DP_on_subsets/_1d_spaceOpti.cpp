#include <iostream>
#include <vector>
using namespace std;

int subsetSum(int n, int sum, vector<int> &arr)
{
    vector<bool> prev(sum+1, false);
    // base case 1
    prev[0] = true;
    // base case 2
    prev[arr[0]] = true;

    for(int i=1;i<n;i++)
    {
        vector<bool> curr(sum+1, false);
        // base case 1
        curr[0] = true;
        for(int j=1;j<=sum;j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if(arr[i] <= j)
            take = prev[j-arr[i]];
            curr[j] = take || notTake;
        }
        prev = curr;
    }
    return prev[sum];
}

int main()
{
    int n, sum, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>sum;
    cout<<subsetSum(n, sum, arr)<<endl;
    return 0;
}
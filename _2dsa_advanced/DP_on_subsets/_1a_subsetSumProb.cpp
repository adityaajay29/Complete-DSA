#include <iostream>
#include <vector>
using namespace std;

bool solve(int i, int sum, vector<int> &arr)
{
    if(sum == 0)
    return true;

    if(i == 0)
    return (arr[0] == sum);

    bool notTake = solve(i-1, sum, arr);
    bool take = false;
    if(arr[i] <= sum)
    take = solve(i-1, sum-arr[i], arr);
    
    return take || notTake;
}

int subsetSum(int n, int sum, vector<int> &arr)
{
    return solve(n-1, sum, arr);
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
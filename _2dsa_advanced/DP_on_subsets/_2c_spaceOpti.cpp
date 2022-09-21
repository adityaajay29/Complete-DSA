#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int arrSum = arr[0];
    for(int i=1;i<n;i++)
    {
        arrSum += arr[i];
    }
    
    if(arrSum %2 == 1)
        return false;
    
    int sum = arrSum/2;
    vector<bool> prev(sum + 1, false);
    
    prev[0] = true;
    
    if(arr[0] <= sum)
    prev[arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        vector<bool> curr(sum+1, false);
        curr[0] = true;
        for(int j=1;j<=sum;j++)
        {
            bool take = false;
            if(arr[i] <= j)
                take = prev[j - arr[i]];
            bool notTake = prev[j];
            curr[j] = take || notTake;
        }
        prev = curr;
    }
    return prev[sum];
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> arr;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<canPartition(arr, n)<<endl;
    return 0;
}
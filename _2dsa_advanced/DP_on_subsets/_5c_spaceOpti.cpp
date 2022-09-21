#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int x : arr)
        sum += x;
    if(sum < d || (sum - d) % 2 == 1)
        return 0;
    
    int target = (sum - d)/2;
    vector<int> prev(target + 1);
    if(arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if(arr[0] != 0 && arr[0]<= target)
        prev[arr[0]] = 1;
    for(int i=1;i<n;i++)
    {
        vector<int> curr(target + 1);
        if(arr[0] == 0)
            curr[0] = 2;
        else
            curr[0] = 1;
        for(int j=0;j<=target;j++)
        {
            int take = 0;
            if(arr[i] <= j)
                take = prev[j - arr[i]];
            int notTake = prev[j];
            curr[j] = (take + notTake) % mod;
        }
        prev= curr;
    }
    return prev[target];
}

int main()
{
    int n, d, val;
    cin>>n;
    vector<int> num;
    int i=n;
    while(i--)
    {
        cin>>val;
        num.push_back(val);
    }
    cin>>d;
    cout<<countPartitions(n, d, num)<<endl;
    return 0;
}
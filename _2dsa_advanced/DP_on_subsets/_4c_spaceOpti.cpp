#include <iostream>
#include <vector>
using namespace std;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0);
    
    prev[0] = 1;
    
    if(num[0] <= tar)
        prev[num[0]] = 1;
    
    for(int i=1;i<n;i++)
    {
        vector<int> curr(tar + 1, 0);
        curr[0] = 1;
        for(int j=1;j<=tar;j++)
        {
            int take = 0;
            if(num[i] <= j)
                take = prev[j - num[i]];
            int notTake = prev[j];
            curr[j] = take + notTake;
        }
        prev = curr;
    }
    return prev[tar];
}

int main()
{
    int n, sum, val;
    cin>>n;
    vector<int> num;
    int i=n;
    while(i--)
    {
        cin>>val;
        num.push_back(val);
    }
    cin>>sum;
    cout<<findWays(num, sum)<<endl;
    return 0;
}
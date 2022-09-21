#include <iostream>
#include <vector>
using namespace std;

// naive approach:O(n2)

int maxSubArraySum(vector<int>v,int n)
{
    int sum=v[0];
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            curr+=v[j];
            sum=max(sum,curr);
        }
    }
    return sum;
}

int main()
{
    vector<int>v{-5,1,-2,3,-1,2,-2};
    int n=v.size();
    cout<<"the max subarray sum is "<<maxSubArraySum(v,n)<<endl;
    return 0;
}
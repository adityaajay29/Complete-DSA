#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int>&v,int n)
{
    vector<int>pSum(n,0);
    pSum[0]=v[0];
    for(int i=1;i<n;i++)
    {
        pSum[i]=pSum[i-1]+v[i];
    }
    return pSum;
}

int main()
{
    vector<int>v{2,8,3,9,6,5,4};
    int n=v.size();
    vector<int>pSum=prefixSum(v,n);
    for(auto x:pSum)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
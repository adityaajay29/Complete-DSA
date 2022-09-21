#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int>v,int n)
{
    vector<int>pSum(n,0);
    pSum[0]=v[0];
    for(int i=1;i<n;i++)
    {
        pSum[i]=pSum[i-1]+v[i];
    }
    return pSum;
}

// subtract the sum till lower range-1 

int getSum(int l,int r,vector<int>v,int n)
{
    vector<int>pSum=prefixSum(v,n);
    if(l!=0)
    {
        return pSum[r]-pSum[l-1];
    }
    else
    return pSum[r];
}

int main()
{
    vector<int>v{2,8,3,9,6,5,4};
    int n=v.size();
    cout<<getSum(2,4,v,n)<<endl;
    return 0;
}
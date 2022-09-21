#include <iostream>
#include <vector>
using namespace std;

vector<int> maxInSubarray(vector<int>arr,int k)
{
    vector<int>v;
    int n=arr.size();
    for(int i=0;i<n-k+1;i++)
    {
        int res=arr[i];
        for(int j=i+1;j<i+k;j++)
        {
            res=max(res,arr[j]);
        }
        v.push_back(res);
    }
    return v;
}

int main()
{
    vector<int>arr{10,8,5,12,15,7,6};
    vector<int>ans=maxInSubarray(arr,3);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// find the max sum of k consecutive elements

int maxSum(vector<int>arr,int n,int k)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    int curr=sum;
    for(int j=k;j<n;j++)
    {
        curr+=arr[j]-arr[j-k];
        sum=max(curr,sum);
    }
    return sum;
}

int main()
{
    vector<int>arr{5,-10,6,90,3};
    int n=arr.size();
    int k=2;
    cout<<"the max sum of "<<k<<" consecutive elements is "<<maxSum(arr,n,k)<<endl;
    return 0;
}
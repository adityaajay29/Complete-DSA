#include <iostream>
#include <vector>
using namespace std;

bool FindEquilibrium(vector<int>arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int leftSum=0;
    for(int i=0;i<n;i++)
    {
        if(leftSum==sum-arr[i])
        return true;
        leftSum+=arr[i];
        sum-=arr[i];
    }
    return false;
}

int main()
{
    vector<int>arr{4,2,-2};
    int n=arr.size();
    cout<<FindEquilibrium(arr,n)<<endl;
    return 0;
}
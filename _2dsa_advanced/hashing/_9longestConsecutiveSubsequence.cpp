#include <iostream>
#include <vector>
using namespace std;

int longestConsSub(vector<int>arr)
{
    int n=arr.size();
    int res=1;
    int count=1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1]==1)
        {
            count++;
        }
        else
        {
            res=max(res,count);
            count=1;
        }
    }
    res=max(res,count);
    return res;
}

int main()
{
    vector<int>arr{91,2,3,4,5,9,22,1,6,8,11,7};
    cout<<"longest subsequence with consecutive integers are "<<longestConsSub(arr)<<endl;
    return 0;
}
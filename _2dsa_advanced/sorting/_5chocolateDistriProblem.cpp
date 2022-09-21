#include <iostream>
#include <vector>
using namespace std;

// there are n packets of chocolates with arr[n] no. of chocolates in each n
// we have to find min diff b/w packet with max chocolates and packet with min chocolates

int minDiff(vector<int>arr,int n,int m)
{
    if(m>n)
    return -1;
    sort(arr.begin(),arr.end());
    // initial res cant be 0
    // since we have to find min, so can be initialised as diff of 1st elements or INT_MAX
    int res=arr[m-1]-arr[0];
    // int res=INT_MAX;
    for(int i=1;i+m-1<n;i++)
    {
        res=min(res,arr[i+m-1]-arr[i]);
    }
    return res;
}

int main()
{
    vector<int>arr{7,3,2,4,9,12,56};
    int n=arr.size();
    int m=3;
    cout<<"the min diff between max chocolate pkt and min chohoclate packet is "<<minDiff(arr,n,m)<<endl;
    return 0;
}
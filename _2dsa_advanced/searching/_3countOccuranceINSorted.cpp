#include <iostream>
#include <vector>
using namespace std;

// approach: using two binary searches
// one to find first occ
// 2nd to find last occ
// result will be ((last occ-first occ)+1)
// TC:O(logn)

int firstOcc(vector<int>arr,int x,int l,int h)
{
    if(l>h)
    return -1;
    int mid=(l+h)/2;
    if(x<arr[mid])
    return firstOcc(arr,x,l,mid-1);
    else if(x>arr[mid])
    return firstOcc(arr,x,mid+1,h);
    else
    {
        if(mid==0 || arr[mid-1]!=arr[mid])
        return mid;
        else
        return firstOcc(arr,x,l,mid-1);
    }
    return -1;
}

int lastOcc(vector<int>arr,int x,int l,int h)
{
    if(l>h)
    return -1;
    int mid=(l+h)/2;
    if(x<arr[mid])
    return lastOcc(arr,x,l,mid-1);
    else if(x>arr[mid])
    return lastOcc(arr,x,mid+1,h);
    else
    {
        if(mid==arr.size()-1 || arr[mid+1]!=arr[mid])
        return mid;
        else
        return lastOcc(arr,x,mid+1,h);
    }
    return -1;
}

int countOcc(vector<int>arr,int x,int l,int h)
{
    int first=firstOcc(arr,x,l,h);
    int last=lastOcc(arr,x,l,h);
    if(first==-1)
    return 0;
    else
    return (last-first+1);
}

int main()
{
    vector<int>arr{1,10,10,20,20,20,40};
    int x=40;
    int l=0;
    int h=arr.size()-1;
    cout<<"total count of "<<x<<" is "<<countOcc(arr,x,l,h)<<endl;
    return 0;
}
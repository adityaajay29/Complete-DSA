#include <iostream>
#include <vector>
using namespace std;

int lastOccurance(vector<int>arr,int x)
{
    int l=0;
    int h=arr.size()-1;
    // equality sign is needed
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(x>arr[mid])
        l=mid+1;
        else if(x<arr[mid])
        h=mid-1;
        else 
        {
            if(mid==arr.size()-1 || arr[mid+1]!=arr[mid])
            return mid;
            else 
            l=mid+1;
        }
    }
    return -1;

    // if(h<l)
    // return -1;
    // int mid=(l+h)/2;
    // if(x<arr[mid])
    // return lastOccurance(arr,x,l,mid-1);
    // else if(x>arr[mid])
    // return lastOccurance(arr,x,mid+1,h);
    // else
    // {
    //     if(mid==arr.size()-1 || arr[mid+1]!=arr[mid])
    //     return mid;
    //     else
    //     return lastOccurance(arr,x,mid+1,h);
    // }
    // return -1;
}

int main()
{
    vector<int>arr{5,10,10,10,10,20,20};
    int x=20;
    cout<<"the last occurance of "<<x<<" is "<<lastOccurance(arr,x)<<endl;
    return 0;
}
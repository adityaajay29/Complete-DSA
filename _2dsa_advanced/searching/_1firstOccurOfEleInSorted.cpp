#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>arr,int ele,int l,int h)
{
    if(l>h)
    return -1;
    int mid=l+(h-l)/2;
    if(ele>arr[mid])
    return binarySearch(arr,ele,mid+1,h);
    else if(ele<arr[mid])
    return binarySearch(arr,ele,l,mid-1);
    // corner case 1:
    // in case the middle ele is the given ele
    // we will check whether it is the 1st occurance or not
    // if not, then again go to left 
    // corner case 2 : if mid=0
    // then return mid
    else
    {
        if(mid==0 || arr[mid-1]!=arr[mid])
        return mid;
        else 
        return binarySearch(arr,ele,l,mid-1);
    }
}

int main()
{
    vector<int>arr{1,10,10,10,20,20,40};
    int l=0;
    int h=arr.size()-1;
    int ele=20;
    cout<<"the 1st occurance of "<<ele<<" is on index "<<binarySearch(arr,ele,l,h)<<endl;
    return 0;
}
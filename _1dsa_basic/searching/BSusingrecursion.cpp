#include <iostream>
using namespace std;

int rbs(int *arr,int low,int high,int x)
{
    if(low>high)
    return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x)
    return mid;
    else if(arr[mid]>x)
    return rbs(arr,low,mid-1,x);
    else
    return rbs(arr,mid+1,high,x);
}

int main()
{
    int arr[]={10,20,25,30,35,40,45};
    int n=7;
    int x=25;
    int low=0;
    int high=n-1;
    cout<<rbs(arr,low,high,x)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

// binary search applicable for sorted arrays only

int binarySearch(int *arr, int &n,int &x)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(x==arr[mid])
        // if(*(arr+mid)==x)
        return mid;
        else if(x<arr[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}

int main()
{
    int arr[]={10,20,25,30,35,40};
    int n=6;
    int x=30;
    cout<<binarySearch(arr,n,x)<<endl;
    return 0;
}
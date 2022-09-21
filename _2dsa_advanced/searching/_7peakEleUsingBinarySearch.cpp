#include <iostream>
#include <vector>
using namespace std;

// approach : look if mid ele is larger than its neihbours
// if it is smaller or equal to its left, then go to left, peak will def be in left
// else go to right, peak will def be in right
// O(logn)
// handle the corner case for mid==0 or mid==n-1

int peakEle(vector<int>arr,int n)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
        return arr[mid];
        else if(mid>0 && arr[mid-1]>=arr[mid])
        h=mid-1;
        else
        l=mid+1;
    }
    // this condition will never occur
    return -1;
}

int main()
{
    vector<int>arr{5,14,16,3,4};
    int n=arr.size();
    cout<<"the peak ele is "<<peakEle(arr,n)<<endl;
    return 0;
}
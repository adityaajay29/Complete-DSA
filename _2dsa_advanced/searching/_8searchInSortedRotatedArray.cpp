#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>arr,int x)
{
    int l=0;
    int h=arr.size()-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==x)
        return mid;
        // checking if left part is sorted
        else if(arr[l]<arr[mid])
        {
            // checking if ele is present in left side
            if(x>=arr[l] && x<arr[mid])
            h=mid-1;
            else
            l=mid+1;
        }
        // else right part is sorted
        else
        {
            // checking if ele is present in right side
            if(x>arr[mid] && x<=arr[h])
            l=mid+1;
            else 
            h=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int>arr{20,30,40,8,9};
    int x=20;
    cout<<"the given ele is present at index "<<binarySearch(arr,x)<<endl;
    return 0;
}
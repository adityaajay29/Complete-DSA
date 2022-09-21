#include <iostream>
using namespace std;

// O(m+n)

void merge2arr(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        cout<<arr1[i++]<<" ";
        else 
        cout<<arr2[j++]<<" ";
    }
    // to print the remaining elements
    while(i<m)
    cout<<arr1[i++]<<" ";
    while(j<n)
    cout<<arr2[j++]<<" ";
    cout<<endl;
}

int main()
{
    int arr1[]={10,15,20,40};
    int arr2[]={5,6,6,10,15};
    merge2arr(arr1,arr2,4,5);
    return 0;
}
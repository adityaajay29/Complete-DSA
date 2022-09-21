#include <iostream>
using namespace std;

// stable algo
// approach: compare elements smaller than pivot, store i left side, then store pivot, then larger elements
// than pivot
void partitiion(int arr[],int n,int p)
{
    int temp=arr[p];
    int tempArr[n];
    int k=0;
    // copying the smaller elements
    for(int i=0;i<n;i++)
    {
        if(arr[i]<temp)
        {
            tempArr[k]=arr[i];
            k++;
        }
    }
    // copying the partition element
    tempArr[k]=temp;
    k++;
    int i=0;
    // copying greater elements
    while(i<n)
    {
        if(arr[i]>temp)
        {
            tempArr[k]=arr[i];
            k++;
        }
        i++;
    }
    // copying elements back to original array
    for(int i=0;i<n;i++)
    arr[i]=tempArr[i];
}

int main()
{
    int arr[]={5,13,6,9,12,11,8};
    partitiion(arr,7,6);
    cout<<"partition around 8 is ";
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
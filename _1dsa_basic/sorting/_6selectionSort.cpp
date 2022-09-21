#include <iostream>
using namespace std;

// O(n2), also theta(n2)
// reduces memory write
// not stable
// inplace algo, doesnt require extra place for sorting

// void selectionSort(int arr[],int n)
// {
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=n-1;j>i+0;j--)
//         {
//             if(arr[j]<arr[j-1])
//             swap(arr[j],arr[j-1]);
//         }
//     }
//     for(int i=0;i<n;i++)
//     cout<<arr[i]<<" ";
// }

// void selectionSort(int arr[],int n)
// {
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+0;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             swap(arr[i],arr[j]);
//         }
//     }
//     for(int i=0;i<n;i++)
//     cout<<arr[i]<<" "; 
// }

// optimised code
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            swap(arr[i],arr[j]);
        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={10,5,8,20,2,18};
    selectionSort(arr,6);
    cout<<endl;
    return 0;
}
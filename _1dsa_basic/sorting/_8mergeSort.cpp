#include <iostream>
using namespace std;

// divide and conqueror approach
// divide the array into two, then recursively sort these two arrays and merge them 
// time complex. is O(nlogn), but O(n) extra space
// stable sorting algo

void merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int arrL[n1];
    int arrR[n2];
    for(int i=0;i<n1;i++)
    {
        arrL[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        arrR[i]=arr[m+1+i];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(arrL[i]<arrR[j])
        {
            arr[k]=arrL[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arrR[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=arrL[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=l+(h-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
int main()
{
    int arr[]={12,54,23,6,21,54,76};
    mergeSort(arr,0,6);
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}

// void merge(int arr[],int l,int m,int r)
// {
//     int n1=m-l+1;
//     int n2=r-m;
//     // creating two aux arrays to store the left and right arrays independently
//     // and then will merge them
//     int leftArr[n1],rightArr[n2];
//     for(int i=0;i<n1;i++)
//     leftArr[i]=arr[l+i];
//     for(int j=0;j<n2;j++)
//     rightArr[j]=arr[m+1+j];
//     int i=0,j=0,k=l;
//     // while elements present in both arrays
//     while(i<n1 && j<n2)
//     {
//         // equality sigh to maintain stability
//         if(leftArr[i]<=rightArr[j])
//         {
//             arr[k]=leftArr[i];
//             k++,i++;
//         }
//         else
//         {
//             arr[k]=rightArr[j];
//             k++,j++;
//         }
//     }
//     // putting the left elemets back to the original array
//     while(i<n1)
//     {
//         arr[k]=leftArr[i];
//         k++,i++;
//     }
//     while(j<n2)
//     {
//         arr[k++]=rightArr[j++];
//         k++,j++;
//     }
// }

// void mergeSort(int arr[],int l,int r)
// {
//     if(l<r)
//     {
//         int m=l+(r-l)/2;
//         mergeSort(arr,l,m);
//         mergeSort(arr,m+1,r);
//         merge(arr,l,m,r);
//     }
// }
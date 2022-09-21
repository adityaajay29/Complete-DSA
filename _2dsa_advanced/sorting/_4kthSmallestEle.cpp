#include <iostream>
#include <vector>
using namespace std;

int lomutoPart(vector<int>&arr,int l,int h)
{
    int pivot=arr[h];
    int small=l-1;
    int large=l;
    for(large=l;large<h;large++)
    {
        if(arr[large]<=pivot)
        {
            small++;
            swap(arr[large],arr[small]);
        }
    }
    swap(arr[small+1],arr[h]);
    return small+1;
}

// void quickSort(vector<int>&arr,int l,int h,int k)
// {
//     if(l<h)
//     {
//         int pivot=lomutoPart(arr,l,h);
//         quickSort(arr,l,pivot-1,k);
//         quickSort(arr,pivot+1,h,k);
//     }
// }

int kthSmallest(vector<int>arr,int l,int h,int k)
{
    while(l<=h)
    {
        int pivot=lomutoPart(arr,l,h);
        if(pivot==k-1)
        return arr[pivot];
        else if(k-1<pivot)
        h=pivot-1;
        else
        l=pivot+1;
    }
    return -1;
}

int main()
{
    vector<int>arr{10,5,30,14,12};
    int l=0;
    int h=arr.size()-1;
    int k=5;
    cout<<"the kth largest ele is "<<kthSmallest(arr,l,h,k)<<endl;
    return 0;
}



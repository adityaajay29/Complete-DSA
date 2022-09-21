#include <iostream>
#include <vector>
using namespace std;

// inversion count is the number of steps after which the array will be sorted
// that is, count the values for which arr[i]>arr[j] for i<j
// using merge sort

int merge(vector<int>arr,int l,int m,int h)
{
    int temp[h+1];
    int inversions=0;
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m && j<=h)
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inversions+=m+1-i;
        }
    }
    while(i<=m)
    temp[k++]=arr[i++];
    while(j<=h)
    temp[k++]=arr[j++];
    for(int i=l;i<=h;i++)
    arr[i]=temp[i];
    return inversions;
}

int divide(vector<int>arr,int l,int h)
{
    int inversions=0;
    if(l<h)
    {
        int m=l+(h-l)/2;
        // total inversions =
        // inversions in left sub array
        // +inversions in right sub array
        // +inversions in merging these parts
        inversions+=divide(arr,l,m);
        inversions+=divide(arr,m+1,h);
        inversions+=merge(arr,l,m,h);
    }
    return inversions;
}

int main()
{
    vector<int>arr{3,1,2};
    cout<<"the number of inversions in this array are ";
    cout<<divide(arr,0,2)<<endl;
    return 0;
}



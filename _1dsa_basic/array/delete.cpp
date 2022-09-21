#include <iostream>
using namespace std;
int del(int arr[],int n,int ele)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        break;
    }
    for(int j=i;j<n-1;j++)
        arr[j]=arr[j+1];
    return arr[n-1];
}
int main()
{
    int n=5;
    int arr[]={3,8,12,5,6};
    int ele=8;
    del(arr,n,ele);
    for(int i=0;i<n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
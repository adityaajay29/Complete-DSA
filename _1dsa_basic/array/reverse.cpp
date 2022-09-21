#include <iostream>
using namespace std;
int* reverse(int arr[],int n)
{
    //{10,5,7,30}
    int start=0,end=n-1;
    //while return is easy to use here, as we will end the iteration when end and start crosses each other
    while(start<end)
        swap(arr[start++],arr[end--]);
    return arr;
}
int main(){
    int n=6;
    int arr[]={8,5,0,10,0,20}; //{20,0,10,0,5,8}
    // int arr[]={8,5,0,10,9,0,20}; //{20,0,9,10,0,5,8}
    reverse(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

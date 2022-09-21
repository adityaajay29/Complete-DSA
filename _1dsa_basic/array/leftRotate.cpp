#include <iostream>
using namespace std;
// void leftRotateOnce(int arr[],int n)
// {
//     //{1,2,3,4,5}
//     for(int i=0;i<n-1;i++)
//     swap(arr[i],arr[i+1]);
// }

int* leftRotateOnce(int arr[],int n)
{
    int temp=arr[0]; //storing arr[0] in temporary variable
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1]; //left shift
    }
    arr[n-1]=temp; //putting arr[0] in last index
    return arr;
}

int* leftRotate(int arr[],int n,int d)
{
    for(int i=0;i<d;i++)
    leftRotateOnce(arr,n);
    return arr;
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int main(){
    int n=5;
    int d=3;
    int arr[]={1,2,3,4,5,}; //{1,2,3,4,5}
                            //{2,3,4,5,1}
                            //{3,4,5,1,2}
    leftRotate(arr,n,d);
    printArray(arr,n);
    return 0;
}
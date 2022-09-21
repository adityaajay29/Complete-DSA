#include <iostream>
using namespace std;
int* zerosAtEnd(int arr[],int n)
{
    int count=0; //count of number of non zero elements
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]); //if the value of ith element is not zero, then swipe it with previous count element
            count++; //no. of non zero elements increased
        }
    }
    return arr;
}
int main(){
    int n=6;
    int arr[]={8,5,0,10,0,20};
    zerosAtEnd(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
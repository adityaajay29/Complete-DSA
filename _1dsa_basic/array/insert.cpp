#include <iostream>
using namespace std;
int insert(int arr[],int n,int ele,int posi)
{
    n++;
    int index=posi-1;
    for(int i=n-1;i>=index;i--)
    arr[i+1]=arr[i];
    arr[index]=ele;
    return arr[n]; 
}

int main()
{
    int arr[5]={5,2,10,20};
    int n=4;
    int ele=8;
    int posi=2;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    insert(arr,n,ele,posi);
    for(int j=0;j<n+1;j++)
    cout<<arr[j]<<" ";
    cout<<endl;
    return 0;
}

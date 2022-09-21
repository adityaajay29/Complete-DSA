#include <iostream>
using namespace std;
int largest(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
    {
    bool flag=true;
    for(int j=0;j<n;j++)
    {
        if(arr[j]>arr[i])
        {
        flag=false;
        break;
        }
    }
    if(flag==true)
    return arr[i];
    }
    return -1; //this will never be reached
}
int main(){
    int n=6;
    int arr[]={5,8,20,10,30,40};
    cout<<largest(arr,n)<<endl;
    return 0;
}
#include <iostream>
using namespace std;
bool elementPresent(int arr[],int s,int e,int x)
{
    if(s>e)
    return false;
    if(arr[s]==x)
    return true;
    if(arr[e]==x)
    return true;
    return elementPresent(arr,s+1,e-1,x);
}

int main()
{
    int arr[]={1,2,3,4,5};
    int x=3;
    int s=0;
    int e=sizeof(arr)/sizeof(arr[0])-1;
    cout<<elementPresent(arr,s,e,x)<<endl;
    return 0;
}
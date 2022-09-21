#include <iostream>
using namespace std;
void prefixSum(int arr[],int n,int sum[])
{
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
}
int main(){
    int n=5;
    int arr[]={10,20,30,40,50};
    int sum[n];
    prefixSum(arr,n,sum);
    for(int i=0;i<n;i++)
    cout<<sum[i]<<" ";
    return 0;
}


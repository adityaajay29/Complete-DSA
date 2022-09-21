#include <iostream>
using namespace std;

// pointers to array give the address of the first element of the array,so no need to use &arr;
// when using pointer to array,no need to use [],simply, int *arr=arr;
// internally, arr[i] (for example) is converted to *(arr+i)

void fun(int *arr,int n)
{
    for(int i=0;i<n;i++)
    // cout<<*(ptr+i)<<" ";
    cout<<arr[i]<<" "; //ptr[i]== *(ptr+i)
}

int main()
{
    int arr[]={4,5,6,7};
    int n=4;
    int *p=arr;
    cout<<(p+1)<<" "<<(*(p+2)+2)<<endl;
    fun(arr,n);
    cout<<endl;
    return 0;
}
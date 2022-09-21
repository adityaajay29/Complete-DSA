#include <iostream>
using namespace std;

int main()
{
    int *arr=new int[6];
    for(int i=0;i<6;i++)
    
    *(arr+i)=i+1;
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
}
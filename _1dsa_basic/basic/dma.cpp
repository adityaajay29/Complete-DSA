#include <iostream>
using namespace std;

// we use "new" to allocate memory dynamically

int main()
{
    int *ptr=new int(67); //in dma, RHS is already an address variable, not a value 
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    *ptr=100;
    cout<<*ptr<<endl;
    delete ptr;
    cout<<*ptr<<endl; 
    int *arr;
    arr=new int[4];
    for(int i=0;i<4;i++)
    arr[i]=i*6+1;
    for(int i=0;i<4;i++)
    cout<<arr[i]<<" ";
    return 0;
}
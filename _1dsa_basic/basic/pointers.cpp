#include <iostream>
using namespace std;

// pointer has 2 tasks, one to store address of a variable, second to dereference a variable

int main()
{
    int x=10; 
    int *ptr; //creting a pointer variable
    ptr=&x; //pointer having the address of x....*ptr dereferences the x i.e., *ptr==x
    cout<<x<<" "<<ptr<<" "<<&x<<" "<<*ptr<<" "<<&ptr<<endl;
    return 0;


    // int *ptr;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl; //segmentation fault, since we havent refered it, we cant derefer
    // return 0;
}
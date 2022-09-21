#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int top=-1;
    int ele;
    //push implementation
    {
        top++;
        arr[top]=ele;
    }
    // pop implementaion
    {
        int store=arr[top];
        top--;
        return store;
        // now when push will be called, 
    }
}
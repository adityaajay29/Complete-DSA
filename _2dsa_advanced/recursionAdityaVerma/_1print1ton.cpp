#include <iostream>
using namespace std;

void print1ton(int n)
{
    if(n<1)
    return;
    print1ton(n-1);
    cout<<n<<endl;
}

void printNto1(int n)
{
    if(n<1)
    return;
    cout<<n<<endl;
    printNto1(n-1);
}

int factorial(int n)
{
    if(n==0 || n==1)
    return 1;
    return factorial(n-1)*n;
}

int main()
{
    int n=5;
    // print1ton(n);
    // printNto1(n);
    cout<<factorial(n);
    return 0;
}
#include <iostream>
using namespace std;

bool powerOf2(int n)
{
    if(n%2 || !n)
    return false;
    if(n==2)
    return true;
    return powerOf2(n/2);
}

int main()
{
    int n=16777216;
    cout<<powerOf2(n)<<endl;
    return 0;
}
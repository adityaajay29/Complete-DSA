#include <iostream>
using namespace std;

// a power of two number has only one bit as set in binary representation
// so, adding(&) it with its precedent will result in 0
// O(1)
// ex : 10000 & 01111 = 0000 
bool powerOf2(int n)
{
    if(n==0)
    return false;
    return ((n&(n-1))==0);
}

int main()
{
    int n=88;
    cout<<powerOf2(n)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int x,y,z,res;
    res=x+y*z;
    // prefix

    // (x+(y*z))
    // (x+(*yz))
    // +x*yz

    // postfix

    // (x+(y*z))
    // (x+(yz*))
    // xyz*+
    return 0;
}
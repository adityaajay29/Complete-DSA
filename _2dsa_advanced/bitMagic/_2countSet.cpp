#include <iostream>
using namespace std;

int main()
{
    int x=13;
    int count=0;
    while(x)
    {
        if((x&1)==1)
        // or if(x%2!=0)
        count++;
        x=x>>1;
        // or x/=2;
    }
    cout<<count;
    return 0;
}
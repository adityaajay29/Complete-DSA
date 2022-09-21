#include <iostream>
using namespace std;
// time:O(no of set bits)

int countSetBits(int &x)
{
    int count=0;
    while(x>0)
    {
        // anding x and x-1 and assigning result to x
        // right most set bit will be 0
        // ex : x=13
        // 1101 & 1100 = 1100, count=1
        // 1100 & 1011 = 1000, count=2
        // 1000 & 0111 = 0000, count=3
        x=(x&(x-1));
        count++;
    }
    return count;
}

int main()
{
    int x=13;
    cout<<countSetBits(x);
    return 0;
}
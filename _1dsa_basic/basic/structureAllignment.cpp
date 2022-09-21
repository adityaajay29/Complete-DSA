#include <iostream>
using namespace std;

struct a
{
    char x; //size 1
    int y; //size 4
    char z; //size 1
};
// }__attribute__((packed)); //to get packed memory

struct b
{
    char x;
    char y;
    int z;
};

int main()
{
    cout<<sizeof(a)<<" "<<sizeof(b)<<endl;
    // cout<<sizeof(int);
    return 0;
}

// from the o/p, it is clear that declaring the variables in a order of increasing or decreasing size
// saves space
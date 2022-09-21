#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
};

bool myComp(point p1, point p2)
{
    // to sort in increasing order of x coordinate
    // return (p1.x<p2.x);
    // to return in decreasing order of y coordinate
    return (p2.x>p1.x);
}

int main()
{
    point arr[]={{4,23},{2,78},{5,90}};
    sort(arr,arr+3,myComp);
    for(auto it:arr)
    cout<<it.x<<" "<<it.y<<" ";
    cout<<endl;
    return 0;
}

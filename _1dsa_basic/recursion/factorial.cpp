#include <iostream>
using namespace std;
// int fact(int n)
// {
//     if(n==0)
//     return 1;
//     else
//     return n*fact(n-1);
// }

int factTailRecursive(int n,int val=1)
{
    if(n==0)
    return val;
    else
        return factTailRecursive(n-1,n*val);
}

int main()
{
    int n;
    cout<<factTailRecursive(4,1)<<endl;
}
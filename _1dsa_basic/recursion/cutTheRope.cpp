#include <iostream>
using namespace std;
int maximum(int i,int j,int k)
{
    if(i>j&&i>k)
    return i;
    else if(j>i&&j>k)
    return j;
    else
    return k;
}

int maxCuts(int n,int a,int b,int c)
{   if(n==0)
    return 0;
    if(n<0)
    return -1;
    maxCuts(n-a,a,b,c);
    maxCuts(n-b,a,b,c);
    maxCuts(n-c,a,b,c);
    int cutMax=maximum(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c));
    // no furthur cut possible
    if(cutMax<0)
    return -1;
    // returning 1st cut + remaining
    return (cutMax+1);
}

int main()
{
    int n=8;
    int a=5,b=2,c=3;
    cout<<maxCuts(n,a,b,c)<<endl;
    return 0;
}
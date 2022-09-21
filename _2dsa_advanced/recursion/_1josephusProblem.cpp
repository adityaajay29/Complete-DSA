#include <iostream>
#include <vector>
using namespace std;

int surviver(int n,int k)
{
    if(n==1)
    return 0;
    return (surviver(n-1,k)+k)%n;
}

// for 1 based indexing
int myJosephus(int n,int k)
{
    return surviver(n,k)+1;
}

int main()
{
    int n=7;
    int k=3;
    vector<int>v(4);
    for(int i=0;i<n;i++)
    v.push_back(i);
    cout<<surviver(n,k)<<endl;
    return 0;
}
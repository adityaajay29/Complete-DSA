#include <iostream>
#include <vector>
using namespace std;

void fun(vector<int>*v)
{
    for(auto x:*v)
    cout<<x<<" ";
}

int main()
{
    vector<int>v;
    for(int i=0;i<4;i++)
    v.push_back(i);
    fun(&v);
    cout<<endl;        
    return 0;
}
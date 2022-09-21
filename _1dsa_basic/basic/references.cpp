#include <iostream>
#include <vector>
using namespace std;

//reference has two functions, one to alias 2 variables, second to get the address on a variable, not to store
// to store the address, we use pointers

void fun(vector <int> &v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    int x=10;
    int &y=x; //y is now same as x, change inanyone will be reflected in both x and y
    y=y+12;
    x=x+10;
    cout<<x<<" "<<y<<endl;
    vector <int>v;
    for(int i=0;i<4;i++)
    {
        v.push_back(i);
    }
    fun(v);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>v{34,2,5,76,12,4};
    sort(v.begin(),v.end());
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());

    // we can also use reverse iterator for vectors, rbegin() and rend()
    // sort(v.rbegin(),v.rend());
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}   
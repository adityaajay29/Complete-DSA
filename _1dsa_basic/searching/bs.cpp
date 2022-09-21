#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>v{20,10,5,7};
    sort(v.begin(),v.end(),greater<int>());
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

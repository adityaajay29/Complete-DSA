#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int,int>mp;
    // mp[0]=1;
    // mp[2]=3;
    // mp[4]=1;
    vector<int>v{1,2,3,1,2,3,3,1,4,5,4,3,2,5,9};
    int i=0;
    while(i<v.size())
    {
        mp[v[i]]++;
        i++;
    }
    for(auto x:mp)
    cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
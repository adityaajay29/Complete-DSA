#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int onlyOddOccur(vector<int>&arr)
{
    unordered_map<int,int>mp;
    for(auto x:arr)
    mp[x]++;
    for(auto x:mp)
    if(x.second%2)
    return x.first;
    return -1;
}

int main()
{
    vector<int>arr{4,5,4,4,4,5,5};
    cout<<onlyOddOccur(arr)<<endl;
    return 0;
}
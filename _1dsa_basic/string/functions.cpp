#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s="aditya ajay";
    cout<<s.find("dit")<<endl;
    cout<<s.substr(3,5)<<endl;
    map<int,int>mp;
    for(auto x:s)
    mp[x]++;
    for(auto x:mp)
    cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

void createMap(unordered_map<int,pair<string,int> >&mp,int i,string u,int v)
{
    mp[i]={u,v};
}

int main()
{
    unordered_map<int,pair<string,int> >mp;
    int n;
    int v;
    string u;
    cout<<"enter n ";
    cin>>n;
    int i=0;
    while(i<n)
    {
        cin>>u>>v;
        createMap(mp,i,u,v);
        i++;
    }
    for(auto x:mp)
    {
        cout<<x.second.first<<" "<<x.second.second<<endl;
    }
    return 0;
}
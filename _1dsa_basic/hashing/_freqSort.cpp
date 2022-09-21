#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct point
{
    int num,freq;
};

bool myComp(point x1,point x2)
    {
        if(x1.freq==x2.freq)
        return(x1.num<x2.num);
        else
        return(x1.freq>x2.freq);
    }

int main()
{
    vector<int>arr{4,4,9,4,2,9,5,9,4};
    map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    vector<point>v;
    for(auto x:mp)
    {
        v.push_back({x.first,x.second});
    }
    sort(v.begin(),v.end(),myComp);
    vector<int>ans;
    for(auto x:v)
    {
        for(int i=0;i<x.freq;i++)
        ans.push_back(x.num);
    }
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// problem to find any index of ele that appears atleast n/2 +1 times in the array

int major(vector<int>v,int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    int found=0;
    for(auto x:mp)
    {
        if(x.second>n/2)
        found=x.first;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==found)
        return i;
    }
    return -1;
}

int main()
{
    vector<int>v{8,3,4,3,3,4,3,3};
    int n=v.size();
    cout<<"the majority ele index is "<<major(v,n)<<endl;
    return 0;
}
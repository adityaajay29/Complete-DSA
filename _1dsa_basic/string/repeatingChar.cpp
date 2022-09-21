#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void check(string &str)
{
    unordered_map<int,int>umap;
    for(int i=0;i<str.size();i++)
    umap[str[i]]++;
    for(auto x:umap)
    {
        // if(x.second>1)
        cout<<x.first<<" "<<x.second<<endl;
    }
}

void check2(string &str)
{
    vector<int>v;
    for(int i=0;i<256;i++)
    v.push_back(0);
    for(int i=0;i<str.size();i++)
    v[str[i]]++;
    for(auto x:v)
    {
        if(x>1)
        cout<<x<<" ";    
    }
}

int main()
{
    string str="geeksforgeeks";
    check(str);
    cout<<endl;
    check2(str);
    return 0;
}
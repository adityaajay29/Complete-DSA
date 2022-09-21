#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int repeatCheck(string &str)
// {
//     int result=INT_MAX;
//     vector<int>v;
//     for(int i=0;i<256;i++)
//     v.push_back(-1);
//     for(int i=str.size()-1;i>=0;i--)
//     {
//         if(v[i]==-1)
//         v[str[i]]=i;
//         else
//         result=v[str[i]];
//     }
//     if(result==INT_MAX)
//     return -1;
//     return result;
// }

void repeatCheck(string str)
{
    unordered_map<char,int>mp;
    for(auto x:str)
    mp[x]++;
    for(auto x:mp)
    if(x.second>1)
    cout<<x.first<<" "<<x.second<<endl;
}

int main()
{
    string str="geeksforgeeks";
    repeatCheck(str);
    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

bool anagram(string &str1, string &str2)
{
    if(str1.size()!=str2.size())
    return false;
    unordered_map<int,int>mp;
    for(auto x:str1)
    mp[x]++;
    for(auto x:str2)
    mp[x]--;
    for(auto x:mp)
    {
        if(x.second!=0)
        return false;
    }
    return true;
}

int main()
{
    string str1="aditya";
    string str2="aaitdy";
    cout<<anagram(str1,str2)<<endl;
    return 0;
}

// int main()
// {
    // string s="aditya ajay";
    // for(auto i=s.rbegin();i!=s.rend();i++)
    // cout<<*i;
    // for(auto x:s)
    // cout<<x;
    // for(int i=s.size();i>=0;i--)
    // cout<<s[i];
    // cout<<endl;
    // return 0;
// }
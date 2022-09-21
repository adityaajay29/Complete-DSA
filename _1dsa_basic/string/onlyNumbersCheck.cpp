#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// string checkNums(string &str)
// {
//     vector<int>ascii;
//     for(int i=0;i<256;i++)
//     {
//         ascii.push_back(0);
//     }
//     for(int i=0;i<str.size();i++)
//     {
//         ascii[str[i]]++;
//     }
//     // for(int i=0;i<ascii.size();i++)
//     // {
//     //     cout<<i<<" "<<ascii[i]<<endl;
//     // }
//     for(int i=0;i<48;i++)
//     {
//         if(ascii[i]!=0)
//         return "no";
//     }
//     for(int i=58;i<256;i++)
//     {
//         if(ascii[i]!=0)
//         return "no";
//     }
//     return "yes";
// }

bool checkNums(string str)
{
    unordered_map<int,int>mp;
    for(auto x:str)
    mp[x]++;
    for(auto x:mp)
    {
        // ascii for digits is from 49 to 57
        if(x.first<48 || x.first>58)
        return false;
    }
    return true;
}

int main()
{
    string str="123234283974983709800786238629387";
    cout<<checkNums(str)<<endl;
    return 0;
}


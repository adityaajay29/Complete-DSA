#include <iostream>
#include <vector>
using namespace std;

void upperCases(string s, string temp, vector<string> &ans)
{
    if(s.empty())
    {
        ans.push_back(temp);
        return;
    }
    string first=temp;
    string second=temp;
    first.push_back(s[0]);
    second.push_back(toupper(s[0]));
    s.erase(s.begin()+0);
    upperCases(s, first, ans);
    upperCases(s, second, ans);
}

int main()
{
    string s;
    cin>>s;
    vector<string> ans;
    upperCases(s, "", ans);
    for(string s: ans)
    cout<<s<<" ";
    return 0;
}
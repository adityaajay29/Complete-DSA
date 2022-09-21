#include <iostream>
#include <vector>
using namespace std;

void permu(string s, vector<string>&ans, string temp)
{
    if(s.size() == 0)
    {
        ans.push_back(temp);
        return;
    }
    string op1=temp;
    string op2=temp;
    op1.push_back('_');
    op1.push_back(s[0]);
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    permu(s, ans, op1);
    permu(s, ans, op2);
}

int main()
{
    string s;
    cin>>s;
    vector<string> ans;
    permu(s, ans, "");
    for(string s: ans)
    cout<<s<<" ";
    return 0;
}
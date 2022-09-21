#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void perm(string s, string temp)
{
    if(s.empty())
    {
        ans.push_back(temp);
        return;
    }
    if(isalpha(s[0]))
    {
        string op1=temp;
        string op2=temp;
        op1.push_back(tolower(s[0]));
        op2.push_back(toupper(s[0]));
        s.erase(s.begin()+0);
        perm(s, op1);
        perm(s, op2);
    }
    else 
    {
        string op1=temp;
        op1.push_back(s[0]);
        s.erase(s.begin()+0);
        perm(s, op1);
    }
}

int main()
{
    string s;
    cin>>s;
    perm(s, "");
    for(string s:ans)
    {
        cout<<s<<" ";
    }
    return 0;
}
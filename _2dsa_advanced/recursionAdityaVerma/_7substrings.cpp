#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void subStrings(string s, string a, int n, int i)
{
    if(i == n)
    {
        ans.push_back(a);
        return;
    }
    subStrings(s, a, n, i+1);
    subStrings(s, a+s[i], n, i+1);
}

void fun(string s, string temp)
{
    if(s.size() == 0)
    {
        ans.push_back(temp);
        return;
    }
    string op1=temp;
    string op2=temp;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    fun(s, op1);
    fun(s, op2);
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    subStrings(s, "", n, 0);
    // fun(s, "");
    for(string x:ans)
    cout<<x<<" ";
    return 0;
}
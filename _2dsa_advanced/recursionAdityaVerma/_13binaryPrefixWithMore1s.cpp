#include <iostream>
#include <vector>
using namespace std;


// can be easily visualised after drawing the recursive tree
// similar to creating balanced parenthisis

void helper(int n, int zeros, int ones, string temp, vector<string> &ans)
{
    if(ones + zeros == n)
    {
        ans.push_back(temp);
        return;
    }
    // if(ones >= 0)
    // {
        string ans1=temp;
        ans1.push_back('1');
        helper(n, zeros, ones+1, ans1, ans);
    // }
    if(ones > zeros)
    {
        string ans2=temp;
        ans2.push_back('0');
        helper(n, zeros+1, ones, ans2, ans);
    }
}

void fun(int n, vector<string> &ans)
{
    helper(n, 0, 0, "", ans);
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<string> ans;
    fun(n, ans);
    for(string s : ans)
    cout<<s<<" ";
    return 0;
}
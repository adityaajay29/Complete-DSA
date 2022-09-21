#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void helper(int open, int close, string temp)
{
    if(open == 0 && close == 0)
    {
        ans.push_back(temp);
        return;
    }
    // opening choice only will be available when opeing will be left 
    if(open > 0)
    {
        // string op1=temp;
        // op1.push_back('(');
        temp.push_back('(');
        helper(open-1, close, temp);
        temp.pop_back();
    }
    // closing choice we will have when closing>opening as, if closing is less or equal to open,
    // then it will never be balanced
    if(close > open)
    {
        // string op2=temp;
        // op2.push_back(')');
        temp.push_back(')');
        helper(open, close-1, temp);
        temp.pop_back();
    }
}

void parenthisis(int n)
{
    int open=n;
    int close=n;
    helper(open, close, "");
    return;
}

int main()
{
    int n;
    cin>>n;
    parenthisis(n);
    for(string s : ans)
    cout<<s<<" ";
    return 0;
}

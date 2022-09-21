#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int precedence(char c)
{
    if(c=='/' || c=='*')
    return 2;
    if(c=='+' || c=='-')
    return 1;
    else return -1;
}

void postfix(string str)
{
    stack<char>s;
    vector<char>v;
    for(int i=0;i<str.size();i++)
    {
        // if operand, then push to array
        if(str[i]=='a'||str[i]=='b'||str[i]=='c'||str[i]=='d'||str[i]=='e')
        v.push_back(str[i]);
        // if no operator in stack, then no comparison
        else if((str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-') && s.empty())
        s.push(str[i]);
        else if((str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-') && (precedence(str[i])>=precedence(s.top())))
        s.push(str[i]);
        else if((str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-') && (precedence(str[i])<precedence(s.top())))
        {
            while((s.empty()!=true) && (precedence(str[i])<=precedence(s.top())))
            {
                v.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(s.empty()!=true)
    {
        v.push_back(s.top());
        s.pop();
    }
    for(auto x:v)
    cout<<x;
}

int main()
{
    string str="a*b/c-d*e";
    postfix(str);
    cout<<endl;
    return 0;
}
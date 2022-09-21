#include <iostream>
#include <stack>
using namespace std;

int operation(char oper,char operand1,char operand2)
{
    int a=(int)operand1-'0';
    int b=(int)operand2-'0';
    if(oper=='*')
    return a*b;
    else if(oper=='/')
    return a/b;
    else if(oper=='+')
    return a+b;
    else if(oper=='-')
    return a-b;
    else 
    return -1;
}

void evaluatePostfix(string str)
{
    stack<char>s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        continue;
        else if(str[i]>='0'&&str[i]<='9')
        s.push(str[i]);
        else if(str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-')
        {

        }
    }
}


#include <iostream>
#include <stack>
using namespace std;
// problem : the bracket opening first should close first

// this is purely a stack problem, as it follows LIFO, the latest opening should close first

// this funcion to check if opening at top of the stack matches the immepdiate closing in string
bool balance(char open, char close)
{
    return((open=='['&& close==']')||(open=='{' && close=='}')||(open=='(' && close==')'));
}

bool balanceCheck(string str)
{
    // checking if given empty string
    if(str=="")
    return false;
    // int stack to store str[i] characters
    stack<char>s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='{' || str[i]=='[' || str[i]=='(')
        // push only the opening braces
        s.push(str[i]);
        // if all poped, and str is not ended, like {[]}]
        // or, starting with closing brace, like ][]
        else if(s.empty())
        return false;
        // check for balance
        else if(!balance(s.top(),str[i]))
        return false;
        // removing the matched item
        else
        s.pop();
    }
    // if successfully matched, then stack should be empty
    // else false will be returned as stack is not empty
    return(s.empty());
}

int main()
{
    string str="[]{()}";
    cout<<balanceCheck(str)<<endl;
    return 0;
}
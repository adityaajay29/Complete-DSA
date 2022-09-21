#include <iostream>
#include <vector>
using namespace std;

bool checkRotation(string &text,string &patt)
{
    text+=text;
    if(text.find(patt)>=0 && text.find(patt)<text.size())
    return true;
    else
    return false;
}

int main()
{
    string text="ABCD";
    string patt="CADB";
    cout<<checkRotation(text,patt)<<endl;
    return 0;
}
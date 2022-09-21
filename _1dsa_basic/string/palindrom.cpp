#include <iostream>
using namespace std;

bool palindrom(string &str,int s,int e)
{
    s=0;
    e=str.length()-1;
    while(s<e||s==e)
    {
        if(str[s++]!=str[e--])
        return false;
    }
    return true;
}

int main()
{
    string str="adda";
    int s=0;
    int e=str.size()-1;
    cout<<palindrom(str,s,e)<<endl;
    return 0;
}
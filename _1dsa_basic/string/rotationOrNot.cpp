#include <iostream>
using namespace std;

bool rotation(string &str1,string &str2)
{
    if(str1.size()!=str2.size())
    return false;
    str1=str1+str1;
    // if(str1.find(str2)>=0 && str1.find(str2)<str1.size())
    // return true;
    // return false;
    return(str1.find(str2)!=string ::npos);
}

int main()
{
    string str1="abba";
    string str2="aabb";
    cout<<rotation(str1,str2)<<endl;
}
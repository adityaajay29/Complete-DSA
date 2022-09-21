#include <iostream>
using namespace std;
void subsets(string str,string current="",int index=0)
{   
    if(index==str.size())
    {
    cout<<current<<" ";
    return;
    }
    subsets(str,current,index+1); //keeping same
    subsets(str,current+str[index],index+1); //adding char of that index to current
}

int main()
{
    string str="abc";
    subsets(str,"",0);
    return 0;
}

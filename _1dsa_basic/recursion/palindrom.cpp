#include <iostream>
using namespace std;
bool palindrom(string &str,int s,int e)
{
    if(s==e||s>e) //s>e means previous characters matched, then onle they crossed, s==e for odd characters
    return 1;
    if(str[s]!=str[e])
    return 0;
    return palindrom(str,s+1,e-1); //returning whatever our recursive fun returns
}

int main()
{
    string str="aditida";
    int n=str.length();
    int e=n-1;
    int s;
    cout<<palindrom(str,0,e)<<endl;
    return 0;
}
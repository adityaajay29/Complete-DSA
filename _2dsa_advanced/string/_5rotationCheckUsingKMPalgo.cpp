#include <iostream>
#include <vector>
using namespace std;

vector<int> fillLPS(string s)
{
    int n=s.size();
    vector<int>lps(n,0);
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
    return lps;
}

bool rotationUsingKMP(string &text,string &patt)
{
    vector<int>lps=fillLPS(patt);
    int n=text.size();
    int n2=patt.size();
    text+=text;
    int n1=text.size();
    if(n!=n2)
    return false;
    int i=0;
    int j=0;
    while(i<n1)
    {
        if(text[i]==patt[j])
        {
            i++;
            j++;
        }
        if(j==n2)
        {
            return true;
        }
        else if(i<n1 && text[i]!=patt[j])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        } 
    }
    return false;
}

int main()
{
    string text="NYKXOX";
    string patt="XOXNYK";
    cout<<rotationUsingKMP(text,patt)<<endl;
    return 0;
}
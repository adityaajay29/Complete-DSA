#include <iostream>
#include <vector>
using namespace std;

// efficient approach to find the matching pattern in the text
// uses the fillLPS array 
// lps array is made for the given pattern 
// now each char starting from index 0 is matched
// print the index of starting indexof the match every time

vector<int> fillLPS(string &s)
{
    int n=s.size();
    vector<int>lps(n,0);
    lps[0]=0;
    int len=0;
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

void KMPalgo(string &text,string &patt)
{
    vector<int>lps=fillLPS(patt);
    int n1=text.size();
    int n2=patt.size();
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
            cout<<i-j<<" ";
            j=lps[j-1];
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
}   

int main()
{
    string text="ABABA";
    string patt="ABA";
    KMPalgo(text,patt);
    cout<<endl;
    return 0;
}